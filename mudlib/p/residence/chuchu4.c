 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 14
#define Y_COOR 2039
#define Z_COOR 50
#define R_FLAG 2062
#define OWNER "chuchu"
#define CLASS "白云城"
inherit ROOM;
void create()
{
set("short", HIB"泼墨斋"NOR);
set("long", 
"这里除了书之外还是书，不见任何摆设，连字画都是直接书于墙上。
    楚楚师承白云岛，自是琴棋书画样样了得，常常在此吟诗作画，舞文弄墨。左侧
壁上所画的是七夕楚楚抚琴于揽月亭，不问可知出自唠叨的手笔：但见画中女子荷袂
蹁跹，羽衣飘舞，其面容姣若春花，媚如秋月，和着花影重重，流水潺潺，竟有说不
出祥和宁静，自是妙不可言。右侧壁上则题赋一首：

    "+HIC"唯其玉兮，生幽谷兮。
    历沧海而不染，渡劫波以尤坚。
    春风之荡荡，夏日之炎炎。
    秋霜之瑟瑟，冬雪之绵绵。
    看风云之变幻，处惊涛之等闲。
    溪鸣潺潺，有清风素月为佳偶；
    兰香袅袅，得鹤舞凤栖之芳邻。
    予天地种灵毓秀，祥瑞异彩尽收。
    不肯红尘轻就。\n\n"NOR


);
        set("exits", ([
		"east" : __DIR__"chuchu2",
	]));
        set("coor/x",X_COOR);
   	set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("room_flag",R_FLAG);
        set("owner", OWNER);
        set("class", CLASS);
        set("indoors","residence");
        setup();
}
void init()
{
        int flag;
        flag = (int) query("room_flag");
        if(flag & 1) set("valid_startroom",1);
        if(flag & 2) set("NONPC",1);
        if(flag & 4) set("no_fight",1);
        if(flag & 8) set("no_magic",1);
        if(flag & 16) set("indoors","residence");
        add_action("do_invite","invite");
        add_action("do_setowner","setowner");
        add_action("do_list","list");
                //add_action("do_sleep", "sleep");
}
int valid_enter(object me)
{
        int flag;
// means no enter at the beginning.
        int enter = 0;
    flag = (int) query("room_flag");
// always let owner go in:
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 16)
        enter = 1;
        if(flag & 512)
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 1024)
        if((string)me->query("class") == (string)query("class"))
        enter = 1;
        if(flag & 2048) 
        {
                if(strlen(query("invite")) && strsrch((string)query("invite"),"["+(string)me->query("id")+"]") != -1)
           enter = 1;
        }
//      write(sprintf("%d", enter));    
        return enter;
}
int do_list()
{
        object me;
        string *list,invitelist;
        me = this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        invitelist = query("invite");
        if (strlen(invitelist))
        {
                list = explode("]"+invitelist+"[", "][");
                write("你邀请了下列玩家到你的房间:\n");
                for(int i=0;i<sizeof(list);i++)
                        write(list[i]+"\n");
        }else
                write("你没有邀请任何人到你的房间。\n");
        return 1;
} 
int do_invite(string arg)
{
        object me;
        string invitelist;
        me= this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        if( !arg )
        {
                write("你要邀请谁? \n");
                return 1;
        }
        invitelist = (string)query("invite");
        if(strlen(invitelist) && strsrch(invitelist,"["+arg+"]") != -1)
        {
                //if the person has already been invited, remove it from invite list.
                invitelist = replace_string(invitelist,"["+arg+"]","");
           set("invite",invitelist);
                write("你将"+arg+"从你的邀请名单中除去。\n");
        }else
        {
                //invite the person.
                if( find_player(arg))
                {
                        if(!strlen(invitelist))
                                set("invite","["+arg+"]");
                        else
                                set("invite",invitelist+"["+arg+"]");
                        write("你邀请"+arg+"来你的房间。\n");
                }else
                {
                        write("咦... 有这个人吗?\n");
                }
        }
        return 1;
} 
int do_setowner(string arg)
{
        string oldowner;
        oldowner = (string)query("owner");
        set("owner",arg);
        write("你将房间的主人暂时设为"+arg+"。\n");
        call_out("set_back",60, oldowner);
        return 1;
} 
int set_back(string oldowner)
{
        set("owner", oldowner);
        return 1;
}
    
