 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void smart_fight(); 
void create()
{
        set_name("云林", ({ "yunlin" }) );
        set("gender", "男性" );
        set("class", "bonze");
        set("title","兴国禅寺云字辈大师");
        set("age", random(40)+20);
        set("cor", 24);
        set("cps", 29);
        set("int", 25);
        set("fle",200);
        set("long", "他是兴国禅寺中颇有威望的云字辈大师。\n");
        set("combat_exp", 6000000);
        set("attitude", "friendly");
        
        set("resistance/kee",10);
        set("resistance/sen",10);
        
        set("max_force", 1500);
        set("force", 1500);
        set("force_factor",60);
        
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
                
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
            set_skill("parry", 120);
            set_skill("lotusforce", 200);
            set_skill("notracesnow",200);
            set_skill("dabei-strike",200);
            set_skill("move",200);
        set_skill("kwan-yin-spells",130);
          set_skill("spells", 150);
          map_skill("spells","kwan-yin-spells");            
            map_skill("move","notracesnow");
            map_skill("force", "lotusforce");
            map_skill("dodge","notracesnow");
            map_skill("unarmed","dabei-strike");
              
        set("chat_chance", 1);
        set("chat_msg", ({
                "云林说道：你见主持吗？\n",
        }) );
        set("inquiry", ([
                "主持" : "主持在后园。\n",
                "master" : "主持在后园。\n",
        ]));
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}
int accept_fight(object me)
{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
} 
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie-bolt");
                return;
        }
        if (random(3)>1) who->perform_action("unarmed.qianshouqianbian");
        return;
}  
