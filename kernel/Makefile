mykernel: shell.o interpreter.o shellmemory.o kernel.o cpu.o pcb.o ram.o
	gcc -o mykernel shell.o interpreter.o shellmemory.o kernel.o cpu.o pcb.o ram.o
shell.o : shell.c
	gcc -c shell.c
interpreter.o: interpreter.c
	gcc -c interpreter.c
shellmemory.o: shellmemory.c
	gcc -c shellmemory.c
kernel.o: kernel.c
	gcc -c kernel.c
cpu.o: cpu.c
	gcc -c cpu.c
pcb.o: pcb.c
	gcc -c pcb.c
ram.o: ram.c
	gcc -c ram.c