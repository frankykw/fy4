 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
        set_name("�����������ʫ�鱮", ({ "�����������ʫ�鱮","shishubei","yuzhishishubei"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "������׫�ģ���֪������Ĵ����������ʫ�鱮\n");
                set("value", 70);
                set("material", "stone");
                set("no_shown",1);
                set("no_get",1);
                set("no_drop",1);
//      if(random(2))
                set("skill", ([
                        "name":                 "puti-steps",   
                        "exp_required": 0,              
                        "sen_cost":     10,     
                        "difficulty":   10,     
                        "max_skill":    49              
                ]) );
/*      else
                set("skill", ([
                        "name":                 "dodge",
                        "exp_required": 0,
                        "sen_cost":             50,
                        "difficulty":   50,
                        "max_skill":    49
                ]) );*/
        }
}   