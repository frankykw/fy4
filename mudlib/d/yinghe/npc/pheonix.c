#include <ansi.h>
inherit NPC; 
void create()
{
    set_name(HIR"火凤"NOR, ({ "red pheonix", "pheonix" }) );
    set("race", "野兽");
    set("gender", "female");
    set("imbs", ({"头部", "身体", "尾巴", "爪子", "翅膀" }));
    set("verbs", ({"bite", "claw", "poke" }));
    set("age", 400);
    set("long", "一个浑身似火的凤凰，金色夹杂在其中更显富丽。\n");
    set("attitude", "heroism");
    set_skill("dodge", 250+random(100));
    set_skill("move", 450+random(200));
    set("combat_exp", 1000000+random(2000000));
        set("bellicosity", 300);
        set("invisibility",1);
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
//            (: sonic_attack :),
    }) ); 
    setup();
} 
void init(){
        object obj, obj2, me; 
        me = this_player();
        if(!interactive(me)){
                return;
        }
        if(NATURE_D->is_day_time()){
                call_out("leaving", 1, me);
        } 
} 
void leaving(object me){
        message_vision(HIG"\n$N发出一声清悦的叫声振翅飞去。\n\n"NOR, this_object(), me);
        destruct(this_object());
        return ;
} 
int waken(object me){ 
        message_vision("$N"HIR"似乎很恼怒$n吵醒了小火凤，巨大的翅膀一伸，如火山爆发般卷出，\n!!啪!!地将$n打苍蝇一样拍在地上。\n"NOR, this_object(), me);
   if(me->query("attribute_mark") != "fire"){
                me->unconcious();
        } else {
                me->set("gin", 100);
                me->set("kee", 100);
                me->set("sen", 100);
        }
        me->delete_temp("yinghe_marks/wake_pheonix"); 
        return 1;
}    
