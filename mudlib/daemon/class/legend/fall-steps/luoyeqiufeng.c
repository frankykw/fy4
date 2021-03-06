 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, yourexp,myexp,cpexp; 
        if(me->query_temp("luoyeqiufeng")+2>time())
                return notify_fail("你刚刚施展过［落叶秋风］！！\n");
        extra = me->query_skill("fall-steps",1);
        if ( extra < 90) return notify_fail("你的［秋风步］还不够纯熟！\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［落叶秋风］只能对战斗中的对手使用。\n");
                
        if (target->query("step_less")==2) 
                return notify_fail(HIW"对方身势灵活，功力深湛，不会被此步法迷惑的。\n"NOR);
                
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");
                
        message_vision(HIY"$N"+HIY"脚踏八方，身行如秋风中的落叶，飘渺不定！\n"NOR,me,target);
                
        me->set_temp("luoyeqiufeng",time());
        
        yourexp=(int)target->query("combat_exp");
        myexp=(int)me->query("combat_exp");
        cpexp=myexp/2+ (4+extra/110)*random(yourexp)/2;
        if(me->query("class") != "legend" && userp(me)) cpexp=(4+extra/150)*random(myexp)/4;
        
        if(yourexp < cpexp)
        {
                message_vision("结果$N被扰得眼花潦乱，接应不暇！\n",target);
                target->start_busy(3);
        }
        else{
           msg = HIR"可惜$N"+HIR"看出了$n"+HIR"的身法，向$p"+HIR"倏然攻击！"NOR;
                COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);        
        }
        return 1;
} 
