 // Room: irongate3.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "玄铁大门");
        set("long", @LONG
一块空地后面，一座黝黑的大铁门伫立在眼前。门前的土地似乎有被人翻动过
的痕迹。
LONG); 
        set("outdoor","yinghe");
        set("objects", ([
                __DIR__"obj/yunbow" : 1,
        ]));
        
        set("item_desc", ([
                "door" : "黝黑的大铁门不知用何物造成，似乎可以打开（ｏｐｅｎ）。\n",
                "大铁门" : "黝黑的大铁门不知用何物造成，似乎可以打开（ｏｐｅｎ）。\n",
        ]));
        set("exits",([
        "south":__DIR__"bowroom",
        ]) ); 
        setup(); 
} 
void init(){
        object bow; 
        add_action("do_open", "open");  
        bow = present("ground bow", this_object());
        if(objectp(bow)){
                bow->set("installed", 1);
                bow->set("owner", "yinghe");
        }
} 
void close_path(){
        object room;
        if( query("exits/north") ) {
        message("vision","哐铛一声大门在你面前关闭。\n",this_object() );
        delete("exits/north");
        room = find_object(__DIR__"irongate2");
        if(!objectp(room)) {
                room = load_object(__DIR__"irongate2");
           }
        message("vision","哐铛一声大门在你面前关闭。\n", room);
                room->delete("exits/south");
        
    }
}
int do_open(string arg){
        object room, me;
        
        me = this_player();
    if( arg=="door" || arg =="大铁门") {
                if(query("exits/north")){
                        return notify_fail("门已经被打开了。\n");
                }
        message_vision("$N往大铁门上轻轻地一推，大铁门缓缓打开。\n", me);
                room = find_object(__DIR__"irongate2");
                if(!objectp(room)){
                        room = load_object(__DIR__"irongate2");
                }
                message("vision", "门被人从另外一边打开。\n", room);
                room->set("exits/south", __DIR__"irongate3");
                set("exits/north", __DIR__"irongate2");
                call_out("close_path", 5);
        }
        else {
                write("你要推什么呢？\n");
        }
        return 1;       
        message_vision("$N伸手推开了大铁门。\n", me);
}       
