#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIM "经验锦囊" NOR, ({ "exp bao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "cloth");
            set("long", "一个能瞬间提升经验的锦囊。\n");
        

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
        if(arg != "exp bao" && arg != "经验锦囊") return 0;
        if(query("opened"))
                return notify_fail("你打开小红包，但里面是空的！\n");
        //gold = new("/obj/money/gold");
        //gold->set_amount(666);
        //gold->set("name","纯金叶子");
        //gold->set("base_unit","张");
        //gold->move(this_player());
        me->add("combat_exp",543210);
        //me->add("potential",3333);
        //me->add("score",222);
        tell_object(me,"\n恭喜恭喜！你被奖励了：\n" + chinese_number(543210) + "点实战经验\n" );
        set("opened",1);
        return 1;//notify_fail(HIR "\n你悄悄打开红包，两眼发光，一阵窃喜！\n\n" NOR);
}
