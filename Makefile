calendar: main.o interact.o reminder.o linked_list.o
	gcc -o calendar main.o reminder.o linked_list.o interact.o

gcal: main.o interact.o reminder.o linked_list.o
	gcc -o src/gcal main.o reminder.o linked_list.o interact.o

main.o: main.c interact.h reminder.h
	gcc -c main.c -o main.o

interact.o: interact.c interact.h
	gcc -c interact.c -o interact.o

reminder.o: reminder.c reminder.h linked_list.h
	gcc -c reminder.c -o reminder.o

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c -o linked_list.o

clean:
	rm -f *.o calendar src/gcal