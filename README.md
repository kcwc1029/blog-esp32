<p align="center">
    TA 寫得很辛苦，能不能幫忙點個右上角的 ⭐ 支持一下(霸脫 QQ)
</p>

## 1. 相關資源

-   [Arduino SpeedUp 系列課程指南 - LazyTomato Lab](https://www.lazytomatolab.com/guide/)
-   [MCU 功能介紹與實作 :: 2023 iThome 鐵人賽](https://ithelp.ithome.com.tw/users/20162670/ironman/6513)
-   https://sites.google.com/hwsh.ylc.edu.tw/alover/%E6%A9%9F%E9%9B%BB%E6%95%B4%E5%90%88/%E5%90%84%E7%A8%AE%E5%B8%B8%E8%A6%8B%E6%A8%A1%E7%B5%84?authuser=0

## 2. 開發版

-   課程選擇：LOLIN D32
    -   [WEMOS D1 LOLIN32 V1.0.0 ESP-32 基於 WIFI 和藍牙 4MB 記憶體 外接 PH2.0 電源插頭 – 台灣物聯科技 TaiwanIOT Studio](https://www.taiwaniot.com.tw/product/wemos-d1-lolin32-v1-0-0-esp-32-%e5%9f%ba%e6%96%bcwifi%e5%92%8c%e8%97%8d%e7%89%994mb-%e8%a8%98%e6%86%b6%e9%ab%94/)

### 2.1. 常見開發版

-   如果使要使用 ESP 相關的開發版，你在網路上一定會看到這些
-   arduino uno R3
-   arduino pico
-   ESP8266
-   D1 mini
-   ESP32
-   LOLIN D32
-   ESP32-S3 (N16R8)

![upgit_20250224_1740373496.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740373496.png)

-   arduino UNO R3、arduino pico
    ![upgit_20250224_1740373575.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740373575.png)

-   ESP8266、D1mini
    ![upgit_20250224_1740373678.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740373678.png)

-   ESP32 系列(ESP32-S3)：LOLIN D32、ESP32-S3 N16R8
    ![upgit_20250224_1740373726.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740373726.png)

![upgit_20250216_1739709906.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250216_1739709906.png)

![upgit_20250224_1740373953.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740373953.png)

![upgit_20250216_1739709918.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250216_1739709918.png)

## 3. 軟體介面：arduino IDE

-   安裝教學：https://www.minwt.com/arduino/22305.html
-   在 arduino IDE 上運行 ESP32 教學：https://ithelp.ithome.com.tw/articles/10327608
-   調整縮排：https://blog.csdn.net/m0_53401243/article/details/128140112

### 3.1. USB 線插入

![gif](./GIF/1739710150904.gif)

### 3.2. 序列埠監控視窗

![upgit_20250219_1739934294.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250219_1739934294.png)

## 4. 基礎外部材料

-   可以把電想像成，在山坡上的蓄水池

-   導體：連接蓄水池的水管
-   電流：

    -   比擬為水流
    -   單位：安培(A)、毫安培(mA) => 1mA = 0.001A

-   電壓：
    -   電位差：水位的高度差異
    -   想像為一個高蓄水池，跟低蓄水池之間的壓力差
    -   高位者為正極，低位者為負極(或接地(GND))

![upgit_20250223_1740296522.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740296522.png)

-   電阻
    ![upgit_20250223_1740296781.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740296781.png)

    -   一般電組
        ![upgit_20250223_1740297041.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740297041.png)
    -   可變電阻
        ![upgit_20250223_1740297058.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740297058.png)
        ![upgit_20250223_1740297069.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740297069.png)

-   麵包版

![upgit_20250219_1739933987.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250219_1739933987.png)

### 4.1. CPU、MPU、MCU、SoC

-   cpu 就是大家知道的中央處理器(central processing unit)
    -   在嵌入式中會稱呼她為 微處理器單元(microprocessor unit, MPU)
-   在開發板上的 MCU（微控制器, Microcontroller Unit）通常包含 CPU 核心、內建記憶體（SRAM & Flash）、類比/數位訊號轉換器（ADC/DAC）及其他周邊控制單元，因此它是一種單晶片系統，可獨立運作。
    -   CPU(執行運算)
    -   Flash(快閃記憶體)
    -   SRAM(資料記憶體)
    -   I/O
-   在手機、PC 上，把特定功能與處理器整合在同一塊晶片上。這種處理器稱呼為 SoC(system on a Chip)

![upgit_20250223_1740298054.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740298054.png)

### 4.2. 以 arduino 為例：

![upgit_20250223_1740298582.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740298582.png)

-   在開發版通電後，他會先執行開機程式(bootloader)，接著執行上一次刷上去的程式。這種存在 flash 中，在 MCU 中開機執行的程式，稱為韌體(firmware)
-   SRAM(Static RAM)：

    -   用來暫存變數與資料（當程式執行時）
    -   電源關閉時，數據會消失
    -   讀取速度最快
    -   Arduino UNO：只有 2KB SRAM
    -   ESP32：內建 520KB SRAM

-   Flash：

    -   存儲容量比 SRAM 大
    -   可用來存放程式碼與重要數據
    -   讀取速度其次
    -   斷電後資料仍然保留
    -   Arduino UNO 有 32KB Flash（存放程式）
    -   ESP32 通常搭配 4MB - 16MB Flash

-   EEPROM(Electrically Erasable Programmable ROM, 電擦可寫記憶體)
    -   可以逐字節存取（不像 Flash 需要整頁刪除後重寫）
    -   適合存放少量、但需要永久保存的設定 => bootloader
    -   讀取速度最慢
    -   Arduino UNO 有 1KB EEPROM
    -   ESP32 沒有內建 EEPROM，但可以用 Flash 模擬 EEPROM 功能

## 5. GPIO

-   LOLIN D32

![upgit_20250217_1739785661.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250217_1739785661.png)

-   ESP32 S3 N16R8
     ![ESP32-S3 GPIO](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250217_1739784581.png)

### 5.1. [Lab：取得開發版晶片編號](./Lab/Get_ChipID/Get_ChipID.ino)

## 6. 序列通信

![upgit_20250219_1739934389.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250219_1739934389.png)

-   當 ESP32 傳送訊號時，會透過開發版上的 USB 轉換晶片傳換成 USB 訊號 => 進入電腦 => 序列埠監控視窗。

### 6.1. 序列輸出

-   傳輸速度(baud rate)：預設為 9600bps(115200bps)，傳送與接收方都要設定相同的數據，否則會出現亂碼。

```
Serial.begin(9600);
Serial.begin(115200);
```

```
// TODO: 在序列埠輸出
Serial.print("Hello World");
Serial.print(age); //送出age變數的內容
Serial.print(size, 2); // 送出size變數的內容,並指定小數點的位數2位
Serial.print(size, BIN); // 以二進制輸出(BIN、OCT、DEC、HEX)
Serial.println(age); // 加上換行符號
```

#### 6.1.1. [Lab：序列埠 (Serial Monitor) 訊息輸出](./Lab/Serial_Monitor_output/Serial_Monitor_output.ino)

### 6.2. 序列輸入

![upgit_20250219_1739935949.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250219_1739935949.png)

-   ESP32 接收訊號後，會將資料存在 buffer 中(一般容量為 64byte)
-   buffer 屬於 queue => (FIFO)

#### 6.2.1. [Lab：序列埠 (Serial Monitor) 訊息輸出，輸入 STOP 離開](./Lab/Serial_Monitor_input/Serial_Monitor_input.ino)

## 7. 數位輸入&輸出(digital)

-   digital 只分為 HIGH 跟 LOW
-   ESP32 分為 3.3V、0V
-   arduino uno 分為 5V、0V(需要降電壓：電阻)

### 7.1. 數位輸出(digital output)

-   範例：LED
-   LED 是一種能夠發光的半導體電子元件
-   1962 年首次出現，早期僅能發出紅光，後來發展出其他顏色的版本。
-   特性：
        -   單向導通（順向偏壓）：只有一個方向可導通（通電）。
        -   電致發光效應：當電流通過時，電子與電洞重合而發出單色光。
        -   採用不同的半導體材料調整波長，影響 LED 發出的光顏色。
        -   高效率、壽命長、不易破損、反應速度快、可靠性高。

#### 7.1.1. [Lab：透過序列控制 LED 發光](./Lab/Serial_Monitor_LED/Serial_Monitor_LED.ino)

![upgit_20250223_1740306024.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740306024.png)

### 7.2. 數位輸入 digital input

-   在使用前，要先將 pin 設定為 input mode => pinmode(腳位, INPUT);
-   開關種類：
    -   單刀單擲 (SPST - Single Pole, Single Throw)：1 個來源，1 個出口
    -   單刀雙擲 (SPDT - Single Pole, Double Throw)： 1 個來源，2 個可切換的路徑
    -   雙刀單擲 (DPST - Double Pole, Single Throw)：
        -   2 個來源，2 個出口
        -   兩個獨立的電路 同時開啟或關閉
    -   雙刀雙擲 (DPDT - Double Pole, Double Throw)：
        -   功能與 SPDT 相似，但有 2 組獨立切換電路
        -   可同時切換 兩個不同的電路

![upgit_20250219_1739941667.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250219_1739941667.png)

-   以邏輯電路來說，若作為輸入 pin，讓 pin 處於空腳位是不建議的，盡量讓 pin 為 HIGH 或 LOW

![upgit_20250219_1739941913.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250219_1739941913.png)

![upgit_20250219_1739941920.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250219_1739941920.png)

#### 7.2.1. Lab：可以先測試【按鈕控制 LED】

-   在不用程式的情況下，在接好 button、LED、電阻後，是可以通過按鈕控制 LED 燈的(按下亮)

![upgit_20250223_1740301687.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740301687.png)

![upgit_20250219_1739941088.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250219_1739941088.png)

#### 7.2.2. [Lab：利用按鈕控制 LED](./Lab/Button_Hold_LED/Button_Hold_LED.ino)

![upgit_20250223_1740301328.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740301328.png)

-   按下開關 LED 亮，放開開關 LED 暗
-   接線：
    -   LED 正極接 GPIO5
    -   開關一邊接 GPIO15

## 8. 類比輸入&輸出(anolog)

-   0 ~ 255（8-bit 分辨率）(對應電壓：0V ~ 3.3V)

### 8.1. analog output

-   0 ~ 4095(對應電壓：0V ~ 3.3V)
-   要將 anolog singal 毒入，需要依靠【類比/數位轉換器 analog to digital convertor, ADC】
-   要使用【ADC】腳位的 Pin
-   可變電阻：參考[【Arduino】可變電阻使用教學 | 瘋狂創客](https://crazymaker.com.tw/arduino-how-to-use-variable-resistor/)

### 8.2. analog input

-   依靠【類比/數位轉換器 digital to analog convertor, DAC】
-   要使用【DAC】腳位的 Pin
-   ESP32 內建 2 個 DAC 輸出通道，分別對應 GPIO25 和 GPIO26：
-   0 ~ 255（8-bit 分辨率）(對應電壓：0V ~ 3.3V)

| **DAC 通道** | **ESP32 腳位** |
| ------------ | -------------- |
| DAC1         | GPIO25         |
| DAC2         | GPIO26         |

```cpp
#define ANA_PIN = 25;
void setup(){
    dacWrite(ANA_PIN, 255); //
}
```

## 9. 開關-按鍵彈跳現象（Debounce）

-   當我們按下 機械開關（Tact Switch）時，按鈕應該是「導通」或「斷開」，但實際上會有短暫的抖動，這就是「彈跳現象（Bounce）」。
-   ![upgit_20250223_1740303419.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740303419.png)
-   解法 1：使用 delay()
-   解法 2：使用函數庫 bounce2

![upgit_20250223_1740301687.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740301687.png)

### 9.1. [Lab：按一下開燈，按一下關燈(使用 delay 處理彈跳訊號)](./Lab/Button_Toggle_LED/Button_Toggle_LED.ino)

### 9.2. [Lab：按一下開燈，按一下關燈(使用 bounce2 處理彈跳訊號)](./Lab/Button_Toggle_LED_Bounce2/Button_Toggle_LED_Bounce2.ino)

## 10. 脈衝寬度調變(Pulse Width Modulation, PWM)

![upgit_20250224_1740386214.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740386214.png)

-   參考：https://shop.mirotek.com.tw/iot/esp32-start-8/
-   以高頻率訊號，去調整電壓改變。
-   DAC 缺失
    -   ESP32 內建的 DAC 解析度只有 8-bit（0~255），但是 PWM 可以提供更高的解析度，通常是 12-bit 或更高（0~4095）。
    -   只能使用 GPIO25 & GPIO26
-   PWM 優勢
    -   任何 GPIO 腳位 都可以用來產生 PWM
    -   可以模擬 更高解析度的類比信號
    -   可以調整 頻率 & 佔空比 (Duty Cycle)
    -   省電、減少硬體資源消耗
-   需要安裝庫

![upgit_20250219_1739948653.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250219_1739948653.png)

## 11. [觸碰輸入](./Lab/GPIO_Touch/GPIO_Touch.ino)

-   ESP32 的特殊腳位【touch】，以感應電容變化量作為輸入。
-   手指觸碰就可以感應到。

## 12. UART

![upgit_20250219_1739950018.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250219_1739950018.png)

-   只要兩條線即能傳輸：TX(傳輸線)、RX(接收線)
-   可以分為單工、雙工、全雙工 => 依需求改變
-   範例：==RS232、數據機、arduino Serial==

![upgit_20250219_1739950105.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250219_1739950105.png)

-   是一種非同步方式，即不需要通過 CLK 作為標準
    -   設定 baud rate(9600bps, 52100bps)

![upgit_20250219_1739951448.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250219_1739951448.png)

### 12.1. macOS 與 Linux 的通訊埠

-   Windows 使用 COM 來代表序列通訊埠
-   macOS 與 Linux 則使用下面兩者來表示通訊埠。
    -   TTY（TeleTYpewriter, 電傳打字機）=> 被動接收數據（例如監聽輸出）
    -   CU（Call-Up，撥號器）=> CU 則用於 主動連接設備（例如傳送指令到 Arduino）

```
// 在 macOS 或 Linux 的終端機 (Terminal) 中，輸入以下指令來查看可用的 TTY 或 CU 設備
ls -l /dev/tty.* // 列出所有 TTY 設備
ls -l /dev/cu.* // 列出所有 CU 設備
```

-   UART 串列通訊、MCU（微控制器）與周邊設備的溝通等等。這些東西通稱為 TTL 訊號(Transistor-Transistor Logic，電晶體-電晶體邏輯)
    -   auduino、ESP32 有內建 TTL 訊號轉 USB 通訊晶片
    -   但並不是每一塊開發版都有

![upgit_20250223_1740304953.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740304953.png)

![upgit_20250223_1740304967.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250223_1740304967.png)

## 13. 藍芽

-   分為：藍牙規格(Specification)及藍牙規範(Profile)。

### 13.1. 藍牙規格(Specification)：定義無線電規格與架構(傳輸速度、傳輸技術、傳輸距離等)

-   藍芽各規格差異

![upgit_20250220_1740057528.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250220_1740057528.png)

-   arduino 的話需要安裝 HC-05、HC-06 藍芽模組(屬於藍芽 3.0)
-   ESP32 內建藍芽 4.2

### 13.2. 藍牙規範(Profile)：定義各種功能(音樂傳輸、遙控功能)

-   藍牙規範有至少 22 種，定義各種功能，以確保裝置的互通性。常見的藍牙規範包括：
    -   A2DP（Advance Audio Distribution Profile）：立體聲音訊傳輸，提供高品質音樂。
    -   AVRCP（A/V Remote Control Profile）：控制音樂播放器：播放、暫停、上/下首、調整音量。
    -   CVC（Clear Voice Capture）：回音與噪音消除技術，增強語音品質。
    -   HFP（Hands-Free Profile）：免持通話，藍牙耳機與手機通話使用。
    -   HID（Human Interface Device Profile）：支援滑鼠、鍵盤等人機介面。
    -   SPP（Serial Port Profile）：取代 RS-232 串列埠，用於數據傳輸。

### 13.3. 藍牙通訊協議 01：藍芽序列傳輸(serial port profile, SPP)

-   屬於 Bluetooth Classic（傳統藍牙），使用 RFCOMM（類似於串列通訊的通訊協定）
-   適合持續大流量的數據傳輸，如串列埠模擬（例如 RS-232）。
-   主要應用於藍牙 2.0/2.1/3.0 的設備，適用於舊式藍牙裝置。
-   耗電較高，適合需要連續大量數據傳輸的應用，如無線串口通訊、音訊流傳輸等。
-   應用：藍牙串口模組（HC-05、HC-06）、舊款藍牙耳機、無線數據傳輸設備。

-   相關指令

```cpp
#include "BluetoothSerial.h" // 引用庫

BluetoothSerial myBT; // 建立物件

// 啟動藍芽功能(並指定藍芽名稱)
myBT.begin("BT:01") // 取名為BT:01

// 檢查藍牙緩衝區有無外部送來的資料:
if(myBT.available())

// 讀取緩衝區的資料:
myBT.read();

// 透過藍牙發送訊息:
myBT.println();
```

#### 13.3.1. [Lab：使用藍芽控制 LED 燈 => 僅適用 android](./Lab/BlueTooth_LED/BlueTooth_LED.ino)

![upgit_20250220_1740060245.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250220_1740060245.png)

-   手機為 master，ESP32 為 slave
-   手機中端使用 APP(僅線 android)：[Serial Bluetooth Terminal - Google Play 應用程式](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=zh-TW)
    -   iphone 掰掰

![upgit_20250220_1740060218.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250220_1740060218.png)

![upgit_20250220_1740060230.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250220_1740060230.png)

#### 13.3.2. [Lab：ESP32 讀取可變電阻的類比訊號，並透過藍芽傳輸到手機](./Lab/Bluetooth_AnalogRead/Bluetooth_AnalogRead.ino)

-   ESP32 讀取感測器訊息後，可以回傳給手機。
-   但要考慮到緩衝區塞滿的問題，有 2 種處理方式：
    -   傳送資料要加 delay()
    -   手機要先送指令詢問，ESP32 才傳資料
-   手機為 master，ESP32 為 slave

#### 13.3.3. Lab：兩個 ESP32 透過藍芽互相傳遞訊息

![upgit_20250220_1740061447.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250220_1740061447.png)

-   要決定誰是 master，誰是 slave

```cpp
void setup() {
    myBT.begin("BT:01", True);  // 加true，代表他是master
}
```

-   [master 程式碼](./Lab/Bluetooth_ESP32_Communicate/Bluetooth_ESP32_Communicate_master.ino)
-   [slave 程式碼](./Lab/Bluetooth_ESP32_Communicate/Bluetooth_ESP32_Communicate_slave.ino)

### 13.4. 藍牙通訊協議 02：BLE（Bluetooth Low Energy）

-   屬於 Bluetooth 4.0+ 之後的標準，專為低功耗設備設計。
-   適合傳輸小量、間歇性的數據，功耗較低，適合感測器、穿戴裝置等應用。
-   應用：心率監測器、智慧手錶、藍牙燈控、BLE 設備掃描。
-   在 BLE 通訊中，ESP32 充當 Peripheral（從設備），iPhone 充當 Central（主設備）：
    -   ESP32 作為 BLE Server，提供 GATT 服務
    -   iPhone 連線後，可讀取或寫入數據
-   arduino 模組的話，就要使用 HM-10 或 AT-09 模組

### 13.5. [使用 remoteXT 進行藍芽通訊](./remoteXY/remoteXY.md#使用remoteXT進行藍芽通訊)

## 14. 網路

### 14.1. IP(網際網路協定)

![upgit_20250225_1740478766.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250225_1740478766.png)

-   192.168.1.25 => 一串 32 位元長度的二進位數字
-   公共 IP：
    -   屬於網路上獨一無二的 IP，
    -   由 ISP(internet service provider，網路服務提供者)分配
-   私人 IP：

### 14.2. getway：

-   如果家中有多台設備需要上網，可以透過 router 處理內網、外網之間介面

### 14.3. mask(子網路遮罩)：

![upgit_20250225_1740479326.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250225_1740479326.png)

### 14.4. MAC

-   實體位置(media acess control, MAC)
-   每個網卡獨一無二的地址，被燒錄在網卡的韌體上
-   08:00:69:02:01:FC => 前三個為製造商編號，後三個為產品編號

### 14.5. port

![upgit_20250225_1740479785.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250225_1740479785.png)

-   IP 比喻為電話號碼的話，port 就像是不同的分機+
-   HTTP(80)、FTP(21)

### 14.6. WiFi

-   電腦使用的無線網路標準是由國際電子工程學會(IEEE)制定的 IEEE 802.11 標準。
-   wifi 標準
        ![upgit_20250220_1740061903.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250220_1740061903.png)

### 14.7. wifi.h

```
// WiFi 連線與管理
WiFi.begin("網路名稱", "密碼")

// 終止 Wi-Fi 連線。
WiFi.disconnect()

// 傳回 Wi-Fi 連線狀態
WiFi.status() //  WL_IDLE_STATUS（閒置）、WL_CONNECTED（已連線）

// 網路掃描
// 掃描無線網路熱點，並傳回找到的網路名稱（SSID）數量，傳回 -1 表示沒有可用熱點。
WiFi.scanNetworks()

// 裝置資訊
WiFi.SSID() // 傳回當前連線的 Wi-Fi 網路名稱（SSID）
WiFi.RSSI() // 傳回 Wi-Fi 訊號強度（單位 dBm）。
WiFi.channel() // 傳回 Wi-Fi 連線頻道。
WiFi.localIP() // 傳回此開發板取得的 IP 位址。
WiFi.macAddress() // 取得網路卡（ESP32 模組）的 MAC 位址
WiFi.firmwareVersion() // 傳回 ESP32 模組的韌體版本。
WiFi.encryptionType() // 傳回 Wi-Fi 網路採用的加密類型，例如 WEP、WPA、WPA2、WPA3 等。
```

### 14.8. [Lab：掃描 wifi 熱點](./Lab/Wifi_Scan/Wifi_Scan.ino)

### 14.9. [Lab：連上基地台](./Lab/ESP32_Wifi_Connect/ESP32_Wifi_Connect.ino)

![upgit_20250225_1740479785.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250225_1740479785.png)

-   ESP32 他只吃 2.4G 的網路歐
-   可以額外開一個檔案 config.h，去寫帳密

```c
// config.h
const char *WIFI_SSID = "輸入熱點名稱";
const char *WIFI_PASSWORD = "輸入熱點密碼";
```

```c
// 主程式
#include "config.h" // 就可以直接去使用WIFI_SSID跟WIFI_PASSWORD了
```

### 14.10. 將開發版本申設定為 wifi 基地台(AP)

-   SP32 可以作為 AP（無線基地台），但它無法直接當作網際網路的熱點，因為 ESP32 本身沒有行動數據（3G/4G/5G）或乙太網路連接的功能
-   當然比市售商品差，只適合簡易且負荷少的應用
-   本身內建 DHCP 服務

```cpp
WiFi.softAP("SSID", password(至少8碼), 通道)
```

-   通道(選用)：可以選 1-13 號，每個通道有自己的頻寬，跳開其他人設定即可

![upgit_20250221_1740115738.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250221_1740115738.png)

#### 14.10.1. [Lab：讓 ESP32 成為 AP，並自動分配 IP（使用 DHCP）](./Lab/ESP32_AP_DHCP/ESP32_AP_DHCP.ino)

### 14.11. HTTP 傳輸方式以及格式

![upgit_20250221_1740116826.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250221_1740116826.png)

-   HTTP 訊息
    ![upgit_20250221_1740116856.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250221_1740116856.png)

### 14.12. [Lab：透過 GET 方式，取得網頁回復](./Lab/ESP32_Wifi_Get/ESP32_Wifi_Get.ino)

### 14.13. ~~Lab：透過 GET 方式在 thingSpeak~~

### 14.14. ~~[(不實作)Lab：透過 POST 方式在 line notify](./Lab/ESP32_Wifi_Post/ESP32_Wifi_Post.ino)~~

-   line notify 已經提用，但可以參考他 POST 的語法

### 14.15. [Lab：將 ESP32 變成網頁伺服器](./Lab/ESP32_WebServer/ESP32_WebServer.ino)

-   引用 WebServer.h
-   可以處理 HTTP，但一次只能處裡一個 client

![upgit_20250221_1740124776.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250221_1740124776.png)

### 14.16. [Lab：利用 HTTP 方式控制 ESP32 上的 LED](./Lab/ESP32_HTTP_LED/ESP32_HTTP_LED.ino)

![upgit_20250221_1740125883.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250221_1740125883.png)

-   ESP32 去連網路後，在做為網頁 server

### 14.17. [(不實作)Lab：利用 HTTP 方式控制 ESP32 上的 LED(ESP32 同時作為 AP)](./Lab/ESP32_HTTP_LED_AP/ESP32_HTTP_LED_AP.ino)

![upgit_20250221_1740126823.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250221_1740126823.png)

-   在沒有無線基地台的情況下，可以將 ESP32 作為 AP(softAP)。
-   未測試

### 14.18. 取得網路時間(NTP)

-   時間是一個很重要的參數，紀錄資料需要時間，平常也會有時間的需求。
-   過往是使用即時模組(real time clock, RTC)，但需要手動調整時間，也會時常不準確
-   網路時間設定(network time protocol, NTP)：與世界協調時間(coordinated universial time)同步，與格林威治標準時間(GMT)相同，可以透過網路去抓取時間。
-   如何從 NTP 取回時間：
    -   使用 port：123，連到 NTP 伺服器取資料
    -   NTP server 傳送時間戳記(TimeStamp)封包
    -   解析出目前日期與時間，再加上偏移量 => 準確時間

![upgit_20250221_1740133295.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250221_1740133295.png)

-   時間格式化顯示範例

```cpp
Serial.println(&timeinfo, "%T");  // 顯示 22:36:47
Serial.println(&timeinfo, "%F %T");  // 顯示 2020-03-18 22:36:47
```

#### 14.18.1. [Lab：ESP32 透過 Wi-Fi 連接 NTP 伺服器來獲取網路時間](./Lab/ESP32_NTP_Time/ESP32_NTP_Time.ino)

### 14.19. [使用 remoteXT 進行 wifi 通訊](./remoteXY/remoteXY.md)

## 15. 伺服馬達

-   可以依照命令作動作(位置，正反轉；改變速度)

![upgit_20250226_1740545510.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250226_1740545510.png)
![upgit_20250226_1740545545.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250226_1740545545.png)

-   引線：電源、GND、singal
-   單個伺服馬達可以直接使用 ESP32 進行供電，如果要接一個以上的話，就需要外部供電
-   需要安裝 ESP32Servo.h

![upgit_20250226_1740545745.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250226_1740545745.png)

```c
#include <ESP32Servo.h>

Servo myServo; // 建立物件
myServo.setPeriodHertz(50); // 設定訊號頻率

myServo.write() // 要求伺服馬達轉到指定角度
```

### 15.1. [Lab：測試伺服馬達是否可以正常運作](./Lab/Servo_Sweep/Servo_Sweep.ino)

### 15.2. [Lab：讀取可變電阻，控制伺服馬達](./Lab/Servo_Pot_Control/Servo_Pot_Control.ino)

## 16. 直流馬達

![upgit_20250226_1740546721.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250226_1740546721.png)

-   ESP32 輸出電流僅 3.3V，無法推動馬達，需要接額外電源
-   實際使用，我們都會透過中介開關控制 => H 橋(L298N、L9110)等驅動晶片達成。

### 16.1. 馬達控制電路

![upgit_20250226_1740540133.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250226_1740540133.png)
![upgit_20250226_1740540155.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250226_1740540155.png)

### 16.2. H 橋

-   四個開關接由電晶體所製
-   反應速度極快 => 以 PWM 控制

![upgit_20250226_1740540223.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250226_1740540223.png)
![upgit_20250226_1740540283.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250226_1740540283.png)

### 16.3. L298N 驅動晶片

![upgit_20250226_1740540395.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250226_1740540395.png)

-   內建雙 H 橋 => 驅動 2 顆馬達

### 16.4. [Lab：ESP32 控制 DC 馬達](https://randomnerdtutorials.com/esp32-dc-motor-l298n-motor-driver-control-speed-direction/)

## 17. 未整理

### 17.1. [Lab：使用 HTTP 操作控制 LED](./未整理Lab/Wifi_LED/Wifi_LED.ino)

## 18. [Lab：讀取 DHT11](./未整理Lab/DHT11_ESP32/DHT11_ESP32.ino)

## 19. [Lab：讀取 DHT11，並在網頁顯示](./未整理Lab/DHT11_ESP32_Wifi/DHT11_ESP32_Wifi.ino)

<p align="center">
  Copyright © 2025 Wei-Cheng Chen
</p>
