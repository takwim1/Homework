# Homework
#include <stdio.h>
#include <string.h>

#define SIZE 10   // حجم المخزن

// تعريف هيكل المخزن الدائري
typedef struct {
    char dataRing[SIZE];  // المصفوفة لتخزين البيانات
    int head;             // مؤشر القراءة
    int tail;             // مؤشر الكتابة
    int count;            // عدد العناصر
} CircularBuffer;

// تهيئة المخزن
void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// التحقق إذا المخزن ممتلئ
int isFull(CircularBuffer *cb) {
    if (cb->count == SIZE)
        return 1;
    else
        return 0;
}

// التحقق إذا المخزن فارغ
int isEmpty(CircularBuffer *cb) {
    if (cb->count == 0)
        return 1;
    else
        return 0;
}

// إضافة عنصر إلى المخزن
void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow\n"); // في حال الامتلاء
        return;
    }

    cb->dataRing[cb->tail] = data;           // تخزين الحرف
    cb->tail = (cb->tail + 1) % SIZE;        // حركة دائرية
    cb->count++;                             // زيادة عدد العناصر
}

// قراءة عنصر من المخزن
char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow\n"); // في حال الفراغ
        return '\0';
    }

    char data = cb->dataRing[cb->head];      // أخذ الحرف
    cb->head = (cb->head + 1) % SIZE;        // حركة دائرية
    cb->count--;                             // إنقاص العدد

    return data;
}

// الدالة الرئيسية
int main() {
    CircularBuffer cb;
    init(&cb);

    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);  // إدخال الاسم

    strcat(name, "CE-ESY");  // إضافة النص المطلوب

    // تخزين كل حرف في المخزن
    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }

    printf("Output: ");

    // قراءة وطباعة البيانات
    while (!isEmpty(&cb)) {
        char c = read(&cb);
        printf("%c", c);
    }

    printf("\n");

    return 0;
}
