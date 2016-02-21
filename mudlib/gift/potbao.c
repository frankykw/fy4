#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIG "潜能锦囊" NOR, ({ "pot bao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "cloth");
            set("long", "一个能将你隐藏的潜能挖掘出来的锦囊。。\n");
        

          }
    ::init_item();
} 
void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 
int do_open(string arg)
{
        object gold, me;
        me = this_player();
        if(arg != "pot bao" && arg != "潜能锦囊") return 0;
        if(query("opened"))
                return notify_fail("你打开小红包，但里面是空的！\n");
        //gold = new("/obj/money/gold");
        //gold->set_amount(666);
        //gold->set("name","纯金叶子");
        //gold->set("base_unit","张");
        //gold->move(this_player());
       // me->add("combat_exp",500000);
        me->add("potential",123456);
        //me->add("score",222);
        tell_object(me,"\n恭喜恭喜！你被奖励了：\n" + chinese_number(123456) + "点潜能\n" );
        set("opened",1);
        return 1;//notify_fail(HIR "\n你悄悄打开红包，两眼发光，一阵窃喜！\n\n" NOR);
}
