#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name("锁麟笼", ({ "wood cage", "cage", "woodcage" }) );
        set_weight(150000);
        set("no_get", 1);
        set("no_drop", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个用不同木料及聆风紫藤做成的木笼。可以用来扑捉猎物，
但是要先安装（ｉｎｓｔａｌｌ）。\n");
                set("value", 20000);
        set("material", "wood");
    }
        ::init_item();
} 
void init(){
        if(this_player()==environment()) {
        add_action("do_install", "install");
    }
} 
int do_install(string arg){
        object me, arrow;
        
        me = this_player();
        if(!arg || (arg != "wood cage" && arg != "cage" && arg != "woodcage")){
                return notify_fail("你要装什么？\n");
        }
        if(present("wood cage", environment(me))){
                return notify_fail("你发现这里已经安装了此物。\n");
        }
        if( environment(me)->query("short") != "黄沙塔"){
                return notify_fail("这里不适合安装此物。\n");
        }
        if(me->query("kee") < 100) {
                return notify_fail("你实在太累了，先休息一下吧。\n");
   }
        tell_object(me, HIG"你仔细地把锁麟笼安装好埋在黄沙下，又细心的抹去四周黄沙上的足迹。\n"NOR);
        message("vision", me->name()+"在黄沙塔的一角不知在鼓捣什么东西。\n", environment(me), me);
        set("long", "黄沙下似乎有什么东西。");
        this_object()->move(environment(me));
        set("owner", me->query("id"));
        set("installed", 1);
        me->receive_damage("kee", 100);
        return 1;
}     
