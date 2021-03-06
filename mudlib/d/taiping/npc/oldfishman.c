#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int suicidal(); 
void create()
{
        set_name("老渔夫",({"old fishman","fishman"}));
        set("title","愿者上钩");
        set("long","青箬笠，绿蓑衣，斜风细雨不需归。这儿虽不是江南，却也有垂钓的渔翁。\n");
        set("gender","男性");
        
        set("age",72);
        set("combat_exp",3000000); 
        
        set("class","beggar");
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 160);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("staff",150);
                        
        set_skill("qidaoforce", 150);
        set_skill("doggiesteps",200);
        set_skill("dragonstrike",170);
        set_skill("dagou-stick",170);
        
        map_skill("unarmed","dragonstrike");
        map_skill("force", "qidaoforce");
        map_skill("dodge","doggiesteps");
        map_skill("move","doggiesteps");
        map_skill("parry","dagou-stick");
        map_skill("staff","dagou-stick");
                 set("chat_chance_combat", 100);
         set("chat_msg_combat", ({

            (: perform_action, "staff.tianxiawugou" :),
            }) ); 
                                
        
        set("resistance/kee",random(30));
        set("resistance/gin",random(30));
        set("resistance/sen",random(30));
                
        set("inquiry", ([
                "龙鲤鱼" :      "什么龙鲤鱼，没听说过。\n",
                "神仙鱼" :      "神仙鱼啊，我在这儿坐了两年才见过一次。不过，它不愿上钩我也不勉强。\n",
                "*":            "噤声，别吓走了我的鱼儿！！\n",
        ]));
           
    
        set("death_msg",CYN"\n$N说：“人生在世不如意。。。”\n"NOR);    
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                50: (: suicidal() :),
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                "老渔夫唱道：“青箬笠，绿蓑衣，斜风细雨不需归。。”\n",
        }) );  
        
//        auto_npc_setup("wang",200,150,0,"/obj/weapon/","fighter_w","fumostaff",2);
   
        setup(); 
        carry_object(__DIR__"obj/shuocloth")->wear();
        carry_object(__DIR__"obj/staff2")->wield();  
}  
int suicidal() {
        object ob,*enemy;
        int i;
        ob=this_object();
        
//        if (check_health(ob,50)) return 1;
        
        enemy=ob->query_enemy();
        for (i=0;i<sizeof(enemy);i++){
                if (enemy[i]->query("combat_exp")>4500000) {
                        command("say 与其死在你手里，还不如去伴我的鱼儿朋友。");
                        message_vision(WHT"只听扑通一声，$N跳进了湖里，再也没有浮起来。。。\n"NOR,ob);
                        destruct(ob);
                        return 1;
                }
        }
        return 1;
}       
