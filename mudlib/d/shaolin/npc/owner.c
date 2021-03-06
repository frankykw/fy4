 inherit NPC;
// inherit  F_MASTER;
void create()
{
    set_name("谢掌柜", ({ "xie zhanggui"}) );
    set("gender", "男性" );
    set("age", 42);
        set("title","神剑山庄 第二代无为清静楼掌柜");
    set("long",
        "这就是无为清静楼谢掌柜，大家一般叫他谢先生，据说武功已出神入化。\n");
    set("combat_exp", 3000000);
    set("reward_npc", 1);
    set("difficulty", 10); 
    set("attitude", "friendly");
    set("max_force",1000);
    set("force",1000);
    set("force_factor",60);
    set("atman",1000);
    set("max_atman",1000);
    set("fly_target",1);
    set_skill("blade", 200);
    set_skill("move",100);
    set_skill("parry",200);
    set_skill("force",80);
    set_skill("cloudforce",60);
    set_skill("dodge", 200);
    set_skill("shenji-blade",150);
    set_skill("shenji-steps",150);
    map_skill("force","cloudforce");
    map_skill("blade","shenji-blade");
    map_skill("parry","shenji-blade");
    map_skill("dodge","shenji-steps");
    map_skill("move","shenji-steps"); 
/*
    create_family("神剑山庄", 2, "无为清静楼掌柜");
    set("rank_nogen",1);
    set("ranks",({"剑奴","剑手","剑士","剑侠","剑王","剑帝","剑圣","剑魂",
                      "剑罡","剑煞","剑仙","剑神"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));
*/ 
    set("chat_chance", 1);
    set("chat_msg", ({
        name()+"道：没想到无情小子在三少爷面前居然这么不堪一击。\n",
            name()+"道：你要去隐世楼非得杀了我才行。\n",
            }) );
    setup();
    add_money("coin", 50);
    carry_object(__DIR__"obj/qingcloth")->wear();
    carry_object(__DIR__"obj/blade")->wield();
} 
void init()
{
        object me,meizhi;
        if(interactive(me = this_player()) && !me->is_fighting() && userp(me) && me->query("marks/少林_神剑_燕十三"))
        {
                remove_call_out("greeting");
                call_out("greeting",2,me);
        }
        add_action("do_answer","answer");
}
void greeting(object me)
{
        if (objectp(me) && present(me,environment(this_object())))
        {
                if (!me->query_temp("pass_xiezhanggui"))
                {
                        message_vision("$N看了$n一眼，冷冷地说：“凭你的功夫，也想去挑战燕十三？ 
你见过燕十三的剑法吗？” (answer yes/no) \n",this_object(),me);
                        me->set_temp("inask",1); 
                }
                
        }
} 
int do_answer(string arg)
{
        object me;
        me = this_player();
        if (arg != "yes" && arg != "no")
   {
                return notify_fail("你只可答yes/no \n");
        }
        if (!me->query_temp("inask"))
        {
                return 0;
        }
        me->delete_temp("inask");
        if (arg == "yes")
        {
                message_vision("$N眼睛一亮，对$n道：“那你给我看看(show)他的剑法是什么样的？” \n",this_object(),me);
                add_action("do_show","show");
        }else
        {
                message_vision("$N对$n说“你连他的剑法都没见过，就不要去送死了。” \n",this_object(),me);
        }
        return 1;
} 
int do_show(string arg)
{
        object me,meizhi;
        me = this_player();
        if (arg != "meizhi" && arg != "削断的梅枝" && arg != "梅枝")
        {
                return 0;
        }
        if (!present("meizhi",me))
        {
                return notify_fail("你身上没有这样东西。\n");
        }
        if (me->query_temp("pass_xiezhanggui"))
        {
                return 0;
        }
        message_vision( "$n拿出削断的梅枝，稳稳地横在$N眼前。 
$N看着梅枝的断口，脸色渐渐变得灰暗，失魂落魄的 
呐呐道：“第十五剑，第十五剑。。。 你去吧。”\n ",this_object(),me);
        me->set_temp("pass_xiezhanggui",1);
        return 1; 
} 
/*
 void attempt_apprentice(object me)
{
    command("say 我只会几招三脚猫的功夫。。。\n");
    me->add_temp("tried",1);
    if(me->query_temp("tried") < random(10)+10)
        return;
    else
        command("smile");
    command("recruit " + me->query("id") );
    return;
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "blademan");
}
*/    
