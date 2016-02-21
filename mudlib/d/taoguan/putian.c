 inherit ROOM;
void create()
{
        int i;
        set("short", "菩提庵");
        set("long", @LONG
这是一间很破烂的小庙，庵堂的光线也不亮，彷佛自古以来阳光就照不
到这里，使得这古老的佛堂平添了几分凄凉之意。佛堂四面黄幔低垂，也看
不出神龛里供的是什麽佛像，案上铺着和神幔同样陈旧的黄缎，低垂到地。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road2",
 
]));
        set("outdoors", "taoguan");
        set("objects", ([
                __DIR__"npc/laoni" : 1,
                __DIR__"npc/nangong_yan" : 1,
                __DIR__"obj/putuan" : 4,
        ]) ); 
        
        set("coor/x",-30);
        set("coor/y",2010);
        set("coor/z",30);  
        setup();
        for(i=0;i<query("stools");i++)
        set("sitdown_person/"+(string)i,0); 
        
} 
int valid_leave(object who,string dir)
{
        if(who->query_temp("state/sit"))
                return notify_fail("你正坐着呢，不能离开！！\n");
        return 1;
} 
int invalid_leave(object who)
{
        //if they leave by illegal means like burn sheets, let's clear the stool states
        object *stools;
        if(who->query_temp("state/sit"))
        {
                who->delete_temp("state/sit");
                stools = children(__DIR__"obj/putuan");
                for(int i = 0;i< sizeof(stools);i++)
                {
                        if (present(stools[i],this_object()) && stools[i]->query("sitdown_person") == who)
                        {
                                stools[i]->delete("sitdown_person");
                                                        }
                }
        }       
        return 0;
}  
