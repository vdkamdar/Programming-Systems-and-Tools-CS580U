

void createKey();
void phase(int num);
char * generatePasscode(int num);

void phase_1(){
	char * pass = generatePasscode(1);
	phase(1);
}
void phase_2(){
	char * pass = generatePasscode(2);
	phase(2);
}
void phase_3(){
	char * pass = generatePasscode(3);
	phase(3);
}
void phase_4(){
	char * pass = generatePasscode(4);
	phase(4);
}
void phase_5(){
	char * pass = generatePasscode(5);
	phase(5);
}
void phase_6(){
	char * pass = generatePasscode(6);
	phase(6);
	createKey();
}
