typedef struct {
    int** class;
    int len;
} MyCalendar;


MyCalendar* myCalendarCreate() {
    MyCalendar *obj = (MyCalendar*)malloc(sizeof(MyCalendar));
    obj->class = (int**)malloc(sizeof(int*) * 10001);
    obj->len = 0;
    return obj;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    for (int i = 0; i < obj->len; i++) {
        if ((start < obj->class[i][0] && end <= obj->class[i][0]) || (start >= obj->class[i][1] && end > obj->class[i][1])) {
            continue;
        } else {
            return false;
        }
    }
    obj->class[obj->len] = (int*)malloc(sizeof(int) * 2);
    obj->class[obj->len][0] = start;
    obj->class[obj->len][1] = end;
    obj->len++;
    return true;
}

void myCalendarFree(MyCalendar* obj) {
    free(obj->class);
    free(obj);
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 
 * myCalendarFree(obj);
*/