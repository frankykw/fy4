 inherit ROOM;
void create()
{
        set("short", "私刑房");
        set("long", @LONG
这里是千金楼逼良为娼的地方。每个不肯就范的姑娘都会被关在这里，不给吃喝。
如还不从，则严刑拷打。墙上和地上都有暗红色的血迹。屋角一张肮脏的小床，床上
发灰的床单，似乎还有老鼠咬过的痕迹。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
         "west" : __DIR__"sr2",
]));
       set("objects", ([
        __DIR__"npc/funu" : 2,
//      __DIR__"obj/broken_cloth" : 2,
                        ]) );  
        set("coor/x",-120);
        set("coor/y",-10);
        set("coor/z",-10);
//      set("refresh_all_items", 1);
        setup(); 
} 
void reset() {
        string item= "broken_cloth";
        int num = 2;
        object obj, *inv;
        
        :: reset();
        
        inv = all_inventory();
        foreach (object ob in inv) 
        {
                if (userp(ob)) continue;
                if (ob->query("id") == "neiyi") destruct(ob);
        }
        while (num--) 
        {
                obj = new(__DIR__"obj/"+item);
                obj->move(this_object());
   }
}      
