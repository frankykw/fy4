 //sfy@fy4
//mod by ice@fy4
#include <ansi.h> 
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill, duration;
        
        if(me->query("class")!="mei")
                return notify_fail("只有松谷庵的圣女才能运用玄心奥妙决。\n");
		skill = me->query_skill("xuanxinjue",1);
		if(skill < 50) 
            return notify_fail("你的玄心奥妙决不够高！\n");
		if(!target) target=me;
        else if( target != me )
	       return notify_fail("你只能将［玄心奥妙］用在自己身上。\n");
	    if( (string)me->query("gender") != "女性" )
            return notify_fail("非女子不能领悟［玄心奥妙］的真谛。\n");
		if( (int)me->query_temp("daoqian") )
            return notify_fail("你已经在施展［玄心奥妙］了。\n");
		if( (int)me->query("force") < 200 )
            return notify_fail("你的内力不够。\n");
		skill = random(skill/4)+skill/2;
		me->add("force", -200);
        message_vision(HIW"\n$N"HIW"一脸圣洁，缓缓念道：【玄-心-奥-妙  万-法-归-宗】。\n"NOR,me);
        message_vision(HIY"一道金色圣光缓缓张开，$N"HIY"的身体随着光芒的摆动而渐渐融入其中．．．\n"NOR,me);
		me->add_temp("apply/iron-cloth", skill);
		me->set_temp("daoqian", 1);
    
		if (me->query("combat_exp")<2500000)        duration = skill;
        else if (me->query("combat_exp")<3500000)       duration=skill*2;
                else duration =skill*5/2;
                
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
                         skill :), duration);
		if( me->is_fighting() ) me->start_busy(2);
        return 1;
} 
void remove_effect(object me,int amount)
{
		me->add_temp("apply/iron-cloth", -amount);
		me->delete_temp("daoqian");
        tell_object(me, HIW"你身上的圣光渐渐消失了。\n"NOR);
} 
