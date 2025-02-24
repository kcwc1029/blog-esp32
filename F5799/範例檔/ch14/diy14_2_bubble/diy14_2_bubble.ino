// 氣泡排序原理與實作
// 參閱13-13頁

int data[] = { 6, 5, 3, 2, 7, 4, 8, 10, 9, 1 }; 

void bubble_sort(int arr[], byte size) {
   for (byte i=0; i<(size-1); i++) {
     for (byte j=0; j<(size-(i+1)); j++) {
       if (arr[j] > arr[j+1]) {
         int temp = arr[j];
         arr[j] = arr[j+1];
         arr[j+1] = temp;
       }
     }
   }
}

void setup(){
  Serial.begin(9600);
  byte size = sizeof(data) / sizeof(int);  // 求取陣列大小
  Serial.print("Array Size: ");
  Serial.println(size);   // 顯示陣列大小
  
  bubble_sort(data, size);  // 執行氣泡排序

  Serial.print("Sorted Array: ");  // 顯示排序後的陣列元素
  for(byte i=0; i<size; i++) {
     Serial.print(data[i]); 
     Serial.print(",");
  }
  Serial.println("");
}

void loop() { }
