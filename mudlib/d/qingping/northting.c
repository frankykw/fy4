 inherit ROOM;
void create()
{
        set("short", "偏厅");
        set("long", @LONG
厅中整洁异常，墙上一幅画，画的是一位少年剑客和一位女子并辔而行，看
姿态似乎是对夫妻，画中神态自若，显然作画之人手笔不凡，你不由仔细端详起
来。一张红木书桌上放着一把琴，尾部焦黑，乃是上好的梧桐木制成，看来这里
的主人文武皆通，才艺俱佳。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
      "south" : __DIR__"ting",
   ])); 
   set("objects", ([
      __DIR__"npc/mo": 1,
   ]) );
 
   set("item_desc", ([
      "picture": "你的目光不有的被画旁的一首词吸引了过去：\n
      楼外垂杨千万缕，
      欲系青春，少住春还去。
      犹自风前飘柳絮，随春且看归何处。 
      绿满山川闻杜宇。
      便做无情，莫也愁人苦。
      把酒送春春不语，黄昏却下潇潇雨。   
．．．
好词啊，好词！！  
\n", 
      "画": "你的目光不有的被画旁的一首词吸引了过去： \n
      楼外垂杨千万缕，
      欲系青春，少住春还去。
      犹自风前飘柳絮，随春且看归何处。 
      绿满山川闻杜宇。
      便做无情，莫也愁人苦。
      把酒送春春不语，黄昏却下潇潇雨。   
．．．
好词啊，好词！！ 
\n", 
   ]) ); 
   set("coor/x",130);
        set("coor/y",2010);
        set("coor/z",0);
        setup();
} 
void init()
{
   add_action("do_play", "play");
} 
int do_play(string arg)
{
   object me;
  
   me = this_player();
   if (!arg || (arg != "qin" && arg != "琴")) return 0;
   if(me->is_fighting()) return notify_fail("你正在跟人拼命耶．．\n");
   if(me->is_busy()) return notify_fail("你正在忙。\n");
   me->start_busy(2);
   message_vision("悦耳的琴声从$N灵巧的手下流出。\n",me);
   return 1;
}     
