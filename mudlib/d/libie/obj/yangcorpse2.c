 // corpse.c
inherit ITEM; 
int decayed; 
void create()
{
        set_name("���ʬ��", ({ "yang's corpse","corpse" }) );
        set("long", "���Ǳ��ز�ͷ���ʬ�壬��ߺ�Ц���ƺ�������ʱ������ǳ����ɡ�\n");
        set("unit", "��" );
        decayed = 0;
//      if( clonep(this_object()) ) call_out("decay", 120, 1);
} 
int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; } 
string short() { return name() + "(" + capitalize(query("id")) + ")"; } 
void decay(int phase)
{
        decayed = phase;
        switch(phase) {
                case 1:
                        say( query("name") + 
"��ʼ�����ˣ�����һ�����ŵĶ����\n" );
                        switch(query("gender")) {
                                case "����":
                                        set_name("���õ���ʬ", ({ "corpse", 
"ʬ��" }) );
                                case "Ů��":
                                        set_name("���õ�Ůʬ", ({ "corpse", 
"ʬ��" }) );
                                default:
                                        set_name("���õ�ʬ��", ({ "corpse", 
"ʬ��" }) );
                        }
                        set("long",     
"���ʬ����Ȼ�Ѿ�����������һ��ʱ���ˣ���ɢ����һ�ɸ�ʬ��ζ����\n");
                        call_out("decay", 120, phase + 1);
                        break;
                case 2:
                        message("vision", query("name") + "���紵Ǭ�ˣ����һ�ߺ��ǡ�\n" ,environment());
                        set_name("һ�߿�Ǭ�ĺ���", ({ "skeleton", "����" }) 
);
                        set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
                        call_out("decay", 60, phase + 1);
                        break;
                case 3:
                        message("vision", "һ��紵������" + query("name") + 
"���ɹǻҴ�ɢ�ˡ�\n" ,environment());
                        if( environment() ) {
                                object *inv;
                                int i;
                                
                                inv = all_inventory(this_object());
                                for(i=0; i<sizeof(inv); i++) 
{
        if((int) inv[i]->query("no_get") ||
        ((int) !inv[i]->value() &&
        (int) !inv[i]->query("value")))
        destruct(inv[i]);
        else
        inv[i]->move(environment());
}
                        }
                        destruct(this_object());
                        break;
        }
} 