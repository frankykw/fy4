 // Room: woods1.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "小树林"); 
        set("long", @LONG
小树林里一片沉寂，连风吹弃木的声音都没有，连风都吹不到
这里。四下阴暗而潮湿，白天看不见太阳．晚上也看不见星辰。就
算是附近村里的人也不敢入林太深，因为只要一迷路就难走得出去。
LONG); 
        //{{ --- by MapMaker
        set("type","forest");
        set("exits",([
        "south":__DIR__"brook",
        "north":__DIR__"woodsedge",
        ]) );
        set("outdoors", "libie");
        set("coor/x",70);
        set("coor/y",220);
        set("coor/z",0);
        //}} 
        setup();
        replace_program(ROOM);
}     
