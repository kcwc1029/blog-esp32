## 1. 使用 remoteXT 進行藍芽通訊

-   官網：https://remotexy.com/en/
-   右邊註冊帳號【sign in】 => 使用 google 帳號就可以了，他隨後會需要使用 google 信箱驗證
-   我看的教學：https://www.youtube.com/watch?v=dyEnOyQS1w8

### 1.1. Lab：基於 remoteXT，以藍芽方式控制 LED 燈

![upgit_20250224_1740398057.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740398057.png)

-   進來畫面
-   ![upgit_20250224_1740398270.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740398270.png)
-   我這邊需要的是切換開關(switch)
-   ![upgit_20250224_1740398367.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740398367.png)
-   切著要設定專案輸出的方式(對著右邊直接點選上去)
-   ![upgit_20250224_1740398417.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740398417.png)
-   ![upgit_20250224_1740398586.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740398586.png)
-   介面做完，也設定好輸出方式後，點選【get source code】
-   按照他的說明去做就可以拉~

-   ![upgit_20250224_1740398719.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740398719.png)
-   STEP01：把 source code 下載下來
-   ![upgit_20250224_1740399005.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740399005.png)
-   STEP02：在 arduino IDE 中下載 RemoteXY library 庫
-   ![upgit_20250224_1740399086.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740399086.png)
-   STEP03：在 source code 中去調試程你的 code => 以本專案為例
-   ![upgit_20250224_1740399485.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740399485.png)
-   ![upgit_20250224_1740399639.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740399639.png)
-   ![upgit_20250224_1740399559.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740399559.png)
-   ![upgit_20250224_1740399599.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740399599.png)
-   STEP04：在手機安裝 RemoteXY app
-   ![upgit_20250224_1740399703.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2025/02/upgit_20250224_1740399703.png)
-   STEP05：連線，使用
