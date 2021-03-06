inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("诸葛神通", ({ "master zhuge","master" }) );
        set("nickname", HIC"傲闲居士"NOR);
        set("gender", "男性" );
        set("age", 64);
        set("str", 30000);
        set("cor", 30000);
        set("cps", 30000);
        set("int", 30000);
        set("per", 30000);
        set("agi", 30000);
	set("attitude","friendly");
        set("max_force", 50000000);
        set("force", 50000000);
        set("force_factor", 50000);
	set("max_kee",9999999);
        set("max_gin",9999999);
        set("max_sen",9999999);
	set("kee",9999999);
	set("gin",9999999);
	set("sen",9999999);
        set("chat_chance", 3);
        set("chat_msg", ({
"诸葛先生哈哈一笑道：“想当年跟大师兄纵横江湖，是何等逍遥痛快，可如今......”\n",
"诸葛先生回过头看着你道：“你可知晓，大师兄隐居昆仑山后，天下便再无一人是我对手！”\n",
"诸葛先生注视着那快牌匾，大笑了几声，又深深叹了口气，到最后竟是沉默不语。\n",
        }) );
 set("long",
		HIR"诸葛先生冷冷扫了你一眼，沉声道：“没大没小，不知规矩！”\n\n\n"NOR
	);
        create_family("快意门", 2, "尊主");
        set("combat_exp", 999999999);
        set("score", 200000);
        set_skill("move", 5000);
        set_skill("dodge", 5000);
        set_skill("parry", 5000);
        set_skill("unarmed", 5000);
        setup();
}
void attempt_apprentice(object me)
{
        command("recruit " + me->query("id") );
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xianren");
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 5000000 ) {
                student->set("title","快意门圣人");
                return ;
        } else
                student->set("title","快意门逍遥仙");
                return ;
}
void init()
{
	object		me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                call_out("greeting", 1, me);
        }
}
int greeting(object me)
{
	object		groom;;
	if((string)me->query("family/family_name")!="快意门") {
	       message_vision(HIR "\n\n$N看了$n一眼,对$n怒喝道：“你是什么身份，快滚出去，莫冒犯了此间主人！”\n" NOR, this_object(), me);
             message_vision(HIY "\n\n$n微一抬手，一道罡气破空而至，把$N撞飞了出去！\n\n\n" NOR, me,this_object());
	       groom = find_object("/d/wiz/hall");
		if(!objectp(groom)) groom = load_object("/d/wiz/hall");
		me->move(groom);
	}
	else {
               if(me->query("id")!="chuer") {
message_vision(HIR "\n\n$N抬起头来，双目精光一闪，睹了$n一眼，说道：“此地非请勿入！”\n" NOR, this_object(), me);
message_vision(HIY "\n\n$n大袖一挥，将$N稳稳当当送了出去!\n\n\n" NOR, me,this_object());
		groom = find_object("/d/wiz/hall");
		if(!objectp(groom)) groom = load_object("/d/wiz/hall");
		me->move(groom);
				}
	else {
     message_vision(CYN "\n$N对$n笑道：你可终于来了！\n" NOR, this_object(), me);
	}
	}
	return 1;
}
