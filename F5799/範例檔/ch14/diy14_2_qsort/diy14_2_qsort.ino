// 快速排序原理與實作
// 參閱13-16頁

int data[] = {32, 170, 6, 85, 24};     // 要被排序的資料陣列
byte size = sizeof(data)/sizeof(int);
byte middle = size / 2;

int cmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void setup() {
    byte n;
  
    Serial.begin(9600);
  
  Serial.println("Before sort:");
    for( n = 0 ; n < 5; n++ ) {
       Serial.print(String("  ") + data[n]);
    }
  
    qsort(data, size, sizeof(int), cmp);
    
    Serial.println("\nAfter sort:");
    for( n = 0 ; n < 5; n++ ) {   
      Serial.print(String("  ") + data[n]);
    }
     
    Serial.println(String("\nMiddle: ") + data[middle]);
}

void loop() { }
