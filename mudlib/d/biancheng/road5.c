 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "С������");
        set("long", @LONG
���������Ŀ��̶���ۼ����������ֵ�������������֣������ǰ��졣��
����һ�������С¥��û�����ƣ�û�н��죬���׵�խ����ֻ�е�����ʱ�Ż��һ
յ������������Ķ����������ĳ��ͣ���ȥʱ�����Ҵ�ææ����ͷ���߳���������
�����棬���Ǻ���������ӡ�
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"road4",
                "west": __DIR__"road6",
                "southwest" : __DIR__"smallroad1",
              //  "north": __DIR__"xiangjulou",
                "south": __DIR__"xiaojinku",
        ]));
        set("objects", ([
                __DIR__"npc/mafangling": 1,
                __DIR__"npc/huamantian": 1,
        ]) );
        set("outdoors", "biancheng");
                set("valid_startroom", 1); 

        set("coor/x",-1140);
        set("coor/y",180);
        set("coor/z",0);
        setup();
       // replace_program(ROOM);
}    