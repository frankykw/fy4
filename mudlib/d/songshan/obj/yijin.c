 inherit ITEM;
void create()
{
        set_name("易筋经", ({ "print" }));
        set_weight(600);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "片");
            set("long",
         "石壁竟然留下了一个达摩面壁姿态的形象！衣褶纹，隐约可见，宛如一幅淡
色的水墨画像。人像上，纹理间更遍布了无数弯弯曲曲的符号！ 
\n");
                set("no_shown", 1);
                set("no_get", 1);       
                set("material", "stone");
                set("skill", ([
                        "name": "yijinjing",
                        "exp_required": 0,
                        "sen_cost": 20,
                        "difficulty": 40,
                        "max_skill": 200
                ]) );
        }
}  
