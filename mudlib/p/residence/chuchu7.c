 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 15
#define Y_COOR 2040
#define Z_COOR 252
#define R_FLAG 2048
#define OWNER "chuchu"
#define CLASS "白云城"
inherit ROOM;
void create()
{
set("short", HIW"揽月亭"NOR);
set("long", 
"一座用沉香木做成的建在高高的假山顶上的小亭。亭子不大，只能容纳几个人
在里面。亭子里有两张小石凳，一个小石桌，一张琴案。
　　由山脚一路通上来是雕成朵朵莲花的模样白石台阶，穿过落英缤纷的小径，一
路走来总感觉全身染满了香气，仿佛由人间步入仙境。桌上放着一盘残棋，还有两
杯香茗，尚有余温。案上有一尾瑶琴和一本曲谱，闲暇时楚楚喜欢来这里抚琴几曲，
唠叨总在一旁倾听，因唠叨生肖属牛，楚楚说自己是“对牛弹琴”，于是亭子里就
多了只小鸭子。 "+HIY"^=^"+NOR"
　　这里是唠叨平时最爱驻足的地方，因为楚楚常常会斜倚阑干，静静的看着山下
的一面湖水许久许久。而当夜幕低垂，皎皎明月点点繁星仿佛触手可及。

    有楹联云：\n
    "+HIC"欲              弄
    乘              清
    风              影 

    茫              怅
    茫              怅
    归              落
    何              谁
    处              家\n\n"NOR
);
        set("exits", ([
		"down" : __DIR__"chuchu6",
	]));

        set("item_desc", ([
        	"qin": "一把古香古色的瑶琴，一看便知是名贵之物。\n",
        	"琴": "一把古香古色的瑶琴，一看便知是名贵之物。\n",
        	"qupu": "上面密密麻麻地记载着楚楚常爱弹的几只曲谱：『清心普善曲』〔qingxin〕、『十
面埋伏曲』〔shimian〕、『百鸟朝凤曲』〔bainiao〕、『碧海潮生曲』〔bihai〕、
『潇湘水云曲』〔xiaoxiang〕、『广陵散』〔guanglingsan〕。\n",
        	"曲谱": "上面密密麻麻地记载着楚楚常爱弹的几只曲谱：『清心普善曲』〔qingxin〕、『十
面埋伏曲』〔shimian〕、『百鸟朝凤曲』〔bainiao〕、『碧海潮生曲』〔bihai〕、
『潇湘水云曲』〔xiaoxiang〕、『广陵散』〔guanglingsan〕。\n",
        ]) );

        set("coor/x",X_COOR);
   	set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("room_flag",R_FLAG);
        set("owner", OWNER);
        set("class", CLASS);
        set("outdoors","residence");
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
        add_action("do_play","play");
}

int do_play(string arg)
{
	int lvl;
	object me;
	
	me=this_player();
	lvl=me->query_skill("music", 1);
	if(arg=="qingxin" || arg=="清心普善曲")
	{
		if(lvl>=200)
		{
		message_vision("$N纤纤素手轻拨琴弦，『清心普善曲』行云流水般从指间滑落。光阴在琴声中流淌，你忘了时间的存在。\n", me);
		message_vision(HIW"曲如其名，清心普善，闻之即可减少胸中烦恶之情，亦可将病痛缓解。 \n"NOR, me);
		me->clear_condition();
		me->set("bellicosity", 0);
		return 1;
		}
		else
		{
		message_vision("$N的琴道修为不够高深，无法弹奏『清心普善曲』。\n", me);
		}
	}
	if(arg=="shimian" || arg=="十面埋伏曲")
	{
		if(lvl>=200)
		{
		message_vision("$N纤纤素手轻拨琴弦，『十面埋伏曲』行云流水般从指间滑落。光阴在琴声中流淌，你忘了时间的存在。\n", me);
		message_vision(HIM"楚汉之争时，汉以十面埋伏之阵击溃楚项，这本是琵琶曲，但经由琴心的别出心裁，改成
古琴曲后，不仅不失那种雄浑壮丽之势，亦多了为楚项悲歌之意，闻者动容，足不能动。 \n"NOR, me);
		return 1;
		}
		else
		{
		message_vision("$N的琴道修为不够高深，无法弹奏『十面埋伏曲』。\n", me);
		}
	}
	if(arg=="bainiao" || arg=="百鸟朝凤曲")
	{
		if(lvl>=200)
		{
		message_vision("$N纤纤素手轻拨琴弦，『百鸟朝凤曲』行云流水般从指间滑落。光阴在琴声中流淌，你忘了时间的存在。\n", me);
		message_vision(HIC"引得青鸟来，举喙解丝索。此曲隐然有王者之意，但其中妙用也是琴心妙手偶得，昔年琴心为宵小所乘，
危在旦夕之际，百般无奈，抚了一曲百鸟朝凤，却引得无数青鸟闻曲而至，舍身护主，方才化险为夷。\n"NOR, me);
		return 1;
		}
		else
		{
		message_vision("$N的琴道修为不够高深，无法弹奏『百鸟朝凤曲』。\n", me);
		}
	}
	if(arg=="bihai" || arg=="碧海潮生曲")
	{
		if(lvl>=200)
		{
		message_vision("$N纤纤素手轻拨琴弦，『碧海潮生曲』行云流水般从指间滑落。光阴在琴声中流淌，你忘了时间的存在。\n", me);
		message_vision(HIB"此曲本为洞箫所奏，但以琴心之能，却也已一尾古琴奏得天地失色，闻者仿佛置于
浩淼碧浪之中，波涛汹涌下，心神已失。\n"NOR, me);
		return 1;
		}
		else
		{
		message_vision("$N的琴道修为不够高深，无法弹奏『碧海潮生曲』。\n", me);
		}
	}
	if(arg=="xiaoxiang" || arg=="潇湘水云曲")
	{
		if(lvl>=200)
		{
		message_vision("$N纤纤素手轻拨琴弦，『潇湘水云曲』行云流水般从指间滑落。光阴在琴声中流淌，你忘了时间的存在。\n", me);
		message_vision(HIG"潇湘水云间，玄鹤唳声声。昔年琴心抚曲引鹤，乘鹤而去，被惊为天人。\n"NOR, me);
		return 1;
		}
		else
		{
		message_vision("$N的琴道修为不够高深，无法弹奏『潇湘水云曲』。\n", me);
		}
	}
	if(arg=="guanglingsan" || arg=="广陵散")
	{
		if(lvl>=200)
		{
		message_vision("$N纤纤素手轻拨琴弦，『广陵散』行云流水般从指间滑落。光阴在琴声中流淌，你忘了时间的存在。\n", me);
		message_vision(HIR"魏晋时，嵇康临刑东市，奏《广陵》一曲，哀叹：广陵散于今绝矣。然幸甚之至，后人以神奇秘谱传之，
记录了这首聂政冲冠一怒刺韩王的名曲。而其中那一股萧杀之气，更是鬼神为之悲泣，天地为之动容。\n"NOR, me);
		return 1;
		}
		else
		{
		message_vision("$N的琴道修为不够高深，无法弹奏『广陵散』。\n", me);
		}
	}
	message_vision("$N试着想弹奏一曲，瑶琴发出悦耳的“叮叮咚咚”声音，不过可惜不成曲调。\n", this_player());
	return 1;
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
    
