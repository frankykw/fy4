 // sillencer@fy4.com
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int fight_pfm( object me, object target);
int no_fight_pfm( object me, object target);
int poisonhim(object me, object target);  
int perform(object me, object target)
{
        object *ob;
        int i, skill, my_exp,his_exp, bonus;
        string msg; 
        if(me->query("class")!="knight")
                return notify_fail("只有快活林弟子才能够使用"+HIG"「归鸿声断残云碧」"NOR+"。\n"); 
        if (me->query_skill("dream-herb",1)<100)
                return notify_fail("你的云梦五花锦还不够纯熟。\n");
                
        if( (int)me->query("force") < 400 ) 
                return notify_fail("你的内力不够！\n"); 
        
        if( (int)me->query("kee") < 250 ) 
                return notify_fail("你的气血不够！\n"); 
                
        if (me->query("marks/云梦暗杀")) no_fight_pfm(me, target);
                else fight_pfm(me,target);
        
        return 1;
                 
} 
int fight_pfm (object me, object target) { 
        object *ob;
        int i, skill, my_exp,his_exp, bonus, num;
        string msg;
        
        if(!me->is_fighting() ) {
                tell_object(me,"「归鸿声断残云碧」只能在战斗中使用。\n");
                return 1;
        }
        
        if (target) {
                   tell_object(me,"「归鸿声断残云碧」不需要指定目标。\n");
                return 1;
        }
        
//      300             
        skill = me->query_skill("herb");
        
        bonus = (me->query("combat_exp")-3000000)/4000*skill/1000;
        if (bonus>skill) bonus= skill;
        if (bonus>0) skill= skill+bonus; 
//      message_vision(" total is "+(string)(skill*3)+".\n",me);        
//      add bonus, 600 total at 7M,
        
        msg = BLINK+GRN"$N真气流转，脸色突然变得碧绿阴沉。。\n\n" NOR; 
        message_vision(msg,me);         
        
        me->add("force", -250);
        me->receive_wound("kee",100);
        me->start_busy(3);
        
        msg = HIG "$N猛一咬舌尖，使出云梦五花锦中至阴至毒的『归鸿声断残云碧』！！ \n碧血有如残云浓雾一般，漫天纷纷洒落。\n\n" NOR;
        message_vision(msg,me);
        
        my_exp=me->query("combat_exp");
        
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++)   {
                if (!living(ob[i]) || ob[i]==me ) continue;
                if (!ob[i]->is_fighting(me)) continue;
                if (ob[i]->query_temp("dot/dream-herb")) continue;
                his_exp=ob[i]->query("combat_exp");
                if (my_exp/2+ random(my_exp/50*skill)>his_exp) {
                        msg =  HIR "五花毒雾无声无息地渗入$n的体内．．．\n" NOR;
                        message_vision(msg,me,ob[i]);
                        message_vision(YEL"$N只觉眼前"+HIG"五"+HIG"彩"+HIM"斑"+HIY"斓"NOR+YEL"，似乎有无数只小虫在飞舞。\n"NOR,ob[i]);
                        num = skill+random(skill*2);
//                      9*(600+random(600*2)= 5400+ random(10800) in 48 sec
//                      message_vision(" it's "+(string)(num)+".\n",me);
                        ob[i]->receive_wound("kee",num,me);
                        ob[i]->set_temp("dot/dream-herb",1);
                   call_out("dot",6,me,ob[i],8,0,skill);           
                } else 
                        tell_object(me,HIW"你的五花毒雾被"+ob[i]->name()+"发现了！！\n"NOR);    
        }
    return 1; 
}  
void dot (object me, object enemy, int total, int count, int amount)
{
        int num;
        if (!enemy->is_fighting(me)|| !enemy ) {
                if (enemy) {
                        message_vision(WHT"$N的脸色慢慢恢复了正常。。\n"NOR,enemy);
                        enemy->delete_temp("dot/dream-herb");
                }
                return;
        }
        message_vision(YEL"$N只觉眼前"+HIG"五"+HIG"彩"+HIM"斑"+HIY"斓"NOR+YEL"，似乎有无数只小虫在飞舞。\n"NOR,enemy);
        num= amount*3+random(amount*3);
//      message_vision(" it's "+(string)(num)+".\n",me);
        enemy->receive_wound("kee",num,me);
        enemy->set_temp("dot/dream-herb",1);
        count= count+1;
        if (count<total) call_out("dot",6,me, enemy,total,count, amount);
                else {
                        message_vision(WHT"$N的脸色慢慢恢复了正常。。\n"NOR,enemy);
                        if (enemy) enemy->delete_temp("dot/dream-herb");
                        return;
        }
        return ;
} 
int no_fight_pfm(object me, object target)
{
        string msg, id_enemy;
        object env, *inv;
        int myexp,yourexp,mylvl,yourlvl,extra,perp;
        int dur,damage;
        int i;
        
        if( environment(me)->query("no_fight")|| environment(me)->query("no_magic") ) {
                tell_object(me,"这里不准用毒。\n");
           return 1;
        }
                
        if (target==me) {
                tell_object(me,"生命可贵，不要自寻死路！\n");
                return 1;
        }
        
        if (target)
        if (target->is_corpse() || !target->is_character()) {
                tell_object(me,"看清楚一点，那不是活物。\n");
                return 1;
        } 
        extra = me->query_skill("dream-herb",1); 
        if( me->query_temp("canyun") )  {
                tell_object(me,"你正在使用"HIC"「归鸿声断残云碧」"NOR"！\n"); 
                return 1;
        }
        if (time()<(me->query_temp("perform/canyun")+10+random(2))) {
                tell_object(me,HIG"你刚使用完"HIC"「归鸿声断残云碧」"HIG"，现在无法使用外功！\n"NOR); 
                return 1;
        }
        me->set_temp("perform/canyun",time()); 
        me->set_temp("canyun", 1);  
        msg = BLINK+GRN"$N真气流转，脸色突然变得碧绿阴沉。。\n\n" NOR; 
        message_vision(msg,me);
        if( target ) {
                msg = HIG "$N猛一咬舌尖，使出云梦五花锦中至阴至毒的『归鸿声断残云碧』！！ \n碧血有如残云浓雾一般，漫天飘落，纷纷洒洒缓缓落在$n身上。\n\n" NOR;
                message_vision(msg,me,target);
                myexp = me->query("combat_exp");
                yourexp = target->query("combat_exp");
                mylvl= me->query_skill("herb"); 
                perp=target->query_skill("perception",1);
                damage = mylvl*mylvl/75;
                dur = (int) me->query_skill("dream-herb")/10 - 5;
                
                me->receive_wound("kee",250);
                me->add("force",-250);
                if (random (mylvl/50*myexp) >= yourexp && random(perp)<150 ) {
                        msg =  HIR "五花毒雾无声无息地渗入$n的体内．．．\n" NOR;
                   message_vision(msg,me,target);
                        target->apply_condition("five-flower",dur + random(dur));
//                      message_vision("it's "+(string)(damage/2+damage)+".\n",me);
                        target->receive_wound("kee", damage/2, me);
                        target->receive_damage("kee", damage, me);
                        COMBAT_D->report_status(target);
                        me->start_busy(1);
                }
                else if(random(mylvl/30*myexp) >= yourexp) {
                        tell_object(me,HIW"你的五花毒雾被"+target->name()+"发现了！！\n"NOR);   
                        target->kill_ob(me);
                        me->kill_ob(target);
                        me->start_busy(3);
                }
                else {
                        msg = HIY"但是五花毒雾被$n护体内力反震，向$N反罩过来！！\n"NOR;
                        message_vision(msg,me,target);
                        me->apply_condition("five-flower",dur + random(dur));
                        me->receive_wound("kee", damage/2, me);
                        COMBAT_D->report_status(me);
                        target->kill_ob(me);
                        me->kill_ob(target);
                        me->start_busy(3);
                }
        }
        else {
                msg = HIG "$N猛一咬舌尖，使出云梦五花锦中至阴至毒的『归鸿声断残云碧』！！ \n碧血有如残云浓雾一般，漫天纷纷洒落。\n\n" NOR;
                message_vision(msg,me);
                me->receive_wound("kee",250);
                me->add("force",-400);
                env = environment(me);
                inv = all_inventory(env);
                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]==me ) continue;
                        if( inv[i]->is_corpse() ) continue;
                        if( !inv[i]->is_character()) continue;
                        poisonhim(me, inv[i]);
                }
                me->start_busy(3);
        }
   me->delete_temp("canyun");
        return 1;
} 
int poisonhim(object me, object target)
{
        string msg;
        int myexp,yourexp,mylvl,yourlvl;
        int dur,damage;
        msg = HIB "$N凝神贯注，漫天的五花毒雾袭向$n！\n\n" NOR;
        message_vision(msg,me,target);
        myexp = me->query("combat_exp");
        yourexp = target->query("combat_exp");
        
        mylvl = me->query_skill("herb");
        yourlvl = target->query_skill("force")/10;
        damage = mylvl*mylvl/75;
        
        dur = (int) me->query_skill("dream-herb")/10 - 5;
        if (random (mylvl/50*myexp) >= yourexp 
                && random(target->query_skill("perception",1))<150) {
                msg =  HIR "五花毒雾无声无息地渗入$n的体内．．．\n" NOR;
                message_vision(msg,me,target);
                target->apply_condition("five-flower",dur + random(dur));
//              message_vision("it's "+(string)(damage/4+damage)+".\n",me);
                target->receive_wound("kee", damage/4, me);
                target->receive_damage("kee", damage, me);
                COMBAT_D->report_status(target);
                me->start_busy(1);
        }
        else if(random(mylvl/30*myexp) >= yourexp) {
                tell_object(me,HIW"你的五花毒雾被"+target->name()+"发现了！！\n"NOR);   
                target->kill_ob(me);
                me->kill_ob(target);
                me->start_busy(3);
        }
        else {
                msg = HIY"但是五花毒雾被$n护体内力反震，向$N反罩过来！！\n"NOR;
                message_vision(msg,me,target);
                me->apply_condition("five-flower",dur + random(dur));
                me->receive_wound("kee", damage/2, me);
           COMBAT_D->report_status(me);
                target->kill_ob(me);
                me->kill_ob(target);
                me->start_busy(3);
        }
} 
