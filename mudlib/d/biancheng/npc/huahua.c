#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void create()
{ 
        set_name("花花道长",({"hua hua","hua"}));
        set("title",WHT"江湖五毒"NOR);
        set("long", "江湖五毒之首，原是武当的护教长老，因贪恋女色被石雁重责后赶出，从
此变本加厉，勾结一批臭味相投之采花贼，足迹遍布中原。\n");
        set("age",59);
        set("gender","男性");
        set("combat_exp", 7000000);
         set("attitude", "aggressive");
        
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
      set("reward_npc", 1);
    set("difficulty", 20);
    
            set("resistance/gin",70);
    set("resistance/kee",70);
    set("resistance/sen",99);
    set("class","wudang");
    
    set_skill("literate", 140);
    set_skill("force", 150);
    set_skill("move", 150);
    set_skill("unarmed", 130);
    set_skill("sword", 200);
    set_skill("parry", 220);
    set_skill("dodge", 160);
    set_skill("changelaw", 210);
    set_skill("three-sword", 200);
    set_skill("taijiforce", 200);
    set_skill("taiji", 150);
    set_skill("foreknowledge",120);
    set_skill("five-steps", 220);
    set_skill("spells",100);
    set_skill("qixing",180);
    set_skill("incarnation",180);
    set_skill("perception", 200);
    map_skill("spells","qixing");
    map_skill("parry", "taiji-sword");
    map_skill("sword", "three-sword");
    map_skill("move", "five-steps");
    map_skill("dodge", "five-steps");
    map_skill("literate", "changelaw");
    map_skill("force", "taijiforce");
    map_skill("unarmed", "taiji"); 
        
        set("no_fly",1);
        
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
   set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
 
            (: cast_spell, "jixing" :),
            (: perform_action, "sword.sancai" :),
             }) ); 

        
         
        /*CHAR_D->setup_char(this_object());
        auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
*/
        setup();
        carry_object("/d/wudang/obj/sword2")->wield();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/biancheng/npc/obj/paper_1");
}  
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        object another;
        message("vision",name() + "诡异地一笑，又成了那个愁眉苦脸的宋富贵。\n", 
                environment(),this_object() );
        another = new(__DIR__"bosssong");
        another->move(environment(this_object()));
        destruct(this_object());
}  
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if(me->query("wanma/棺材之谜"))
                        me->set_temp("wanma/江湖五毒c",1);
        ::die();
}
