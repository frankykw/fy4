 // heaven_soldier.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        string *order = ({"��", "��", "��", "��", "��", "��", "��", "��", "��", "��"}); 
        set_name("��" + (order[random(10)]) + "���", ({ "heaven soldier", "heavensoldier" }) );
        set("long", "����һλ���������ػ���ר�ŵ��λ���֮��\n");
        set("attitude", "friendly"); 
        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000); 
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);
        set("no_fly",1);
        set("no_arrest",1); 
        set("str", 40);
        set("cor", 30);
        set("cps", 25); 
        set("combat_exp", 100000); 
        set_skill("sword", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 70);
        set_skill("five-steps",70);
        set_skill("three-sword",70);
        map_skill("sword","three-sword");
        map_skill("parry","three-sword");
        map_skill("dodge","five-steps");
        setup(); 
        carry_object(__DIR__"obj/golden_armor")->wear();
        carry_object(__DIR__"obj/golden_sword")->wield();
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
        object *pros,owner;
        
        message("vision",
                HIY + name() + "˵����ĩ������ٻ��������Ѿ���ɻ������񣬾ʹ˸�ǣ�\n\n"
                + name() + "����һ����⣬���������ʧ�����ˡ�\n" NOR, environment(),
                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("max_guard",-1);                
                pros = owner->query_temp("protectors");
                pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
        destruct(this_object());
} 
void invocation(object who, int level)
{
        int i, bonus_skill;
        object *enemy,*pros;
        
        set("str",10+level/16+random(level/16));
        set("agi",10+level/10);
        set("cor",15+random(level/12));
        
        set("max_kee",300+random(level*level/60));
        set("eff_kee",query("max_kee"));
        set("kee",query("max_kee"));
        set("max_gin",query("max_kee")/2);
        set("gin",query("max_kee")/2);
        set("eff_gin",query("max_kee")/2);
        set("max_sen",query("max_kee")/2);
        set("eff_sen",query("max_kee")/2);
        set("sen",query("max_kee")/2);
        
        
   set("max_force",500+random(level*level/200));
        set("force",query("max_force"));
        
        bonus_skill = 50 + level/4 + random(level/4);
        set_skill("sword", 50 + level/4 + random(level/4));
        set_skill("parry", 50 + level/4 + random(level/4));
        set_skill("dodge", 50 + level/4 + random(level/4));
        set_skill("move", 50 + level/4 + random(level/4));
        set_skill("five-steps",20 + level/4 + random(level/4));
        set_skill("three-sword",20 + level/4 + random(level/4));
        
        set("combat_exp", 20000 + level/8*level*level/2+random(level/8*level*level/2));   
        pros = who->query_temp("protectors");
        if(sizeof(pros))
                pros += ({ this_object() });
        else
                pros = ({ this_object() });
        who->set_temp("protectors",pros);
        message("vision",
                HIY "һ��������������������߳�һ��������ɫս�۵Ľ��١�\n\n"
                + name() + "˵����ĩ������ٻ�������������\n" NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
        set("possessed",who);
}
void die()
{
        int i;
        object owner, *enemy,*pros;
        if(objectp(owner=query("possessed")))
        {
        pros = owner->query_temp("protectors");
        pros -= ({ this_object() });
        owner->set_temp("protectors",pros);             
        enemy = query_enemy();
                owner->add_temp("max_guard",-1);        
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        } 
        }
        ::die(); 
} 
void heart_beat()
{
        object leader;
        
        ::heart_beat();
        
        if(query_temp("is_unconcious")||is_busy())
                return ;
        if(query("possessed"))
        {
                leader=query("possessed");
                if(environment(leader)!=environment()&&(!leader->is_ghost()))
                {
                        message_vision("$N�Ҵ���ȥ��\n",this_object());
                        this_object()->move(environment(leader));
                        message_vision("$N���˹�����\n",this_object());
                        delete("leave_room");
                }
        }
        
        else
        {
                if(!query("leave_room"))
                        set("leave_room",1);
                else
                   add("leave_room",1);
                if(query("leave_room")==5)
                        leave();
        }
}       