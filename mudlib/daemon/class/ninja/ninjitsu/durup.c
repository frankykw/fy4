 // void_sense.c
#include <ansi.h> 
inherit SSERVER;
int conjure(object me, object target)
{
        int lvl,i,extra;
        object env, *inv;
        
//      if (me->query("class")!="ninja")
//              return notify_fail("只有忍者才能用忍术.\n");
        
        if(me->query_temp("ninjitsu_durup")) return notify_fail("你现在已经处在精神的极度亢奋状态了。\n");
        
        lvl = (int) me->query_skill("magic");
                
        if ( (int) me->query_skill("ninjitsu",1) <= 50)
                return notify_fail("你忍术不够高！\n");
        if( target != me ) 
                return notify_fail("你只能用在自己的身上。\n");        
            
        if( me->query("atman") < 300 )
                return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 250 )
                return notify_fail("你的精不够！\n");
        me->add("atman", -300);
        me->receive_damage("gin", 250);
        
        extra=lvl/2;
        me->add_temp("apply/durability",extra);
        me->set_temp("ninjitsu_durup",1);
        me->set_temp("mark/no_uncon",1);
        message_vision(HIM "$N的眼光变得迷离，似乎已经被一种强大的精神力量所控制．．．\n" NOR, me);
            
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me ,extra:), lvl/10);
        if( me->is_fighting() ) me->start_busy(2);
        return 1; 
}
void remove_effect(object me,int extra)
{
        me->add_temp("apply/durability", - extra);
        me->delete_temp("ninjitsu_durup");
        me->delete_temp("mark/no_uncon");
        message_vision(HIW"$N的眼神恢复正常，看来已经回到了清醒状态。\n"NOR,me);
        
}     
