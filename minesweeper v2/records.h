struct record {
	char name[40];
	int time;//����������
	record* next;
};
void addRecord(char name[40], int time);
void showRecord();
void reader();
void writer();
void sort();

