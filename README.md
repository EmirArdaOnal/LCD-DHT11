# LCD-DHT11 With I2C
Temperature project that can be done using LCD screen and DHT11


1. İlk olarak gerekli kütüphaneler `LiquidCrystal_I2C` ve `dht` import edilir.
2. `dht` sınıfından `DHT` adında bir nesne tanımlanır.
3. `DHT11_PIN` adında bir sabit değişken oluşturulur ve DHT11 sensörünün veri pini olarak belirlenir (Pin 2 olarak örneklendirilmiştir).
4. `LiquidCrystal_I2C` sınıfından `lcd` adında bir nesne oluşturulur ve I2C adresi (0x27), LCD ekranın sütun sayısı (16) ve satır sayısı (2) parametre olarak verilir.
5. `setup()` fonksiyonu Arduino başlangıcında bir kez çağrılır.
   - `DHT11_PIN` pin modu `INPUT` olarak ayarlanır.
   - `lcd.begin(16, 2)` ile LCD ekran başlatılır ve sütun ve satır sayısı belirtilir.
   - `lcd.setCursor(0, 0)` ile imleç birinci satırın başlangıcına konumlandırılır.
   - `lcd.print("Sicaklik: ")` ile "Sicaklik: " yazısı LCD ekrana yazdırılır.
   - `lcd.setCursor(0, 1)` ile imleç ikinci satırın başlangıcına konumlandırılır.
   - `lcd.print("Nem: ")` ile "Nem: " yazısı LCD ekrana yazdırılır.
6. `displayTemperature()` fonksiyonu, sıcaklık değerini LCD ekranda görüntülemek için kullanılır.
   - `lcd.setCursor(10, 0)` ile imleç sıcaklık değerinin yazılacağı konuma konumlandırılır.
   - `lcd.print(temperature)` ile sıcaklık değeri yazdırılır.
   - `lcd.print(" C")` ile birim olarak "C" yazısı yazdırılır.
7. `displayHumidity()` fonksiyonu, nem değerini LCD ekranda görüntülemek için kullanılır.
   - `lcd.setCursor(6, 1)` ile imleç nem değerinin yazılacağı konuma konumlandırılır.
   - `lcd.print(humidity)` ile nem değeri yazdırılır.
   - `lcd.print("%")` ile birim olarak "%" yazısı yazdırılır.
8. `loop()` fonksiyonu sürekli olarak çalışır.
   - `DHT.read11(DHT11_PIN)` ile DHT11 sensöründen sıcaklık ve nem değerleri okunur.
   - `readData` değişkenine okunan veri atanır.
   - Eğer veri okuma işlemi başarılı ise, sıcaklık ve nem değerleri `temperature` ve `humidity` değişkenlerine atanır.
   - `displayTemperature(temperature)` ve `displayHumidity(humidity)` fonksiyonlarıyla LCD ekrana sıcaklık ve nem değerleri yazdırılır.
   - Ardından `delay(2000)` ile 2 saniye bekleme yapılır ve döngü tekrar başa döner.


LCD ekranı Arduino'ya bağlamak için aşağıdaki adımları uygulayabilirsiniz:

1. LCD ekranınızın I2C arabirimine sahip olduğunu kontrol edin. Eğer I2C arabirimine sahip değilse, LCD ekranıyla doğrudan bağlantı yapmanız gerekecektir.

2. LCD ekranınızın pimlerini kontrol edin. Genellikle VCC, GND, SDA ve SCL gibi pimler bulunur.

3. Arduino Uno'da I2C arabirimini kullanmak için A4 (SDA) ve A5 (SCL) pinlerini kullanırız. Bu pinleri kullanacağımızı belirtmek için kablo bağlantılarını yapmalıyız.

   - LCD ekranınızın VCC pimini Arduino'nun 5V pinine bağlayın.
   - LCD ekranınızın GND pimini Arduino'nun GND pinine bağlayın.
   - LCD ekranınızın SDA pimini Arduino'nun A4 (SDA) pinine bağlayın.
   - LCD ekranınızın SCL pimini Arduino'nun A5 (SCL) pinine bağlayın.


4. LCD ekranını kullanabilmek için `LiquidCrystal_I2C` kütüphanesini yükleyin. Bunun için Arduino IDE'de "Kütüphane Yöneticisi"ni açın, arama çubuğuna "LiquidCrystal_I2C" yazın ve gelen sonuçlardan doğru kütüphaneyi seçerek yükleyin.




# LCD-DHT11 not with I2C

1. İlk olarak, `dht` ve `LiquidCrystal` kütüphanelerini içeri aktarıyoruz. Bu kütüphaneler Arduino IDE'de önceden yüklenmiş olmalıdır.

2. Ardından, `dht` kütüphanesi ile DHT11 sensörünü temsil etmek üzere `DHT` adında bir nesne oluşturuyoruz.

3. `DHT11_PIN` sabitini tanımlayarak DHT11 sensörünün sinyal hattının Arduino'da bağlı olduğu pinin numarasını belirtiyoruz.

4. LCD ekranı için `LiquidCrystal` sınıfından bir nesne oluşturuyoruz ve bağlantı pinlerini belirtiyoruz. Örnekte, RS pini Arduino'nun 12. pini, Enable pini 11. pini, D4 pini 5. pini, D5 pini 4. pini, D6 pini 3. pini ve D7 pini 2. pini olarak tanımlanmıştır. Bu pin numaralarını LCD ekranınıza göre değiştirmeniz gerekebilir.

5. `setup()` fonksiyonunda, LCD ekranını başlatıyoruz ve ilk satıra "Sicaklik: " yazdırıyoruz. İkinci satıra geçerek "Nem: " yazdırıyoruz.

6. `loop()` fonksiyonunda, DHT11 sensöründen veri okumak için `DHT.read11()` fonksiyonunu kullanıyoruz ve okuma sonucunu `readData` değişkenine atıyoruz.

7. Okuma başarılıysa, DHT11 sensöründen alınan sıcaklık ve nem değerlerini `DHT.temperature` ve `DHT.humidity` özelliklerinden alıyoruz ve `temperature` ve `humidity` değişkenlerine atıyoruz.

8. `displayTemperature()` fonksiyonunu çağırarak sıcaklık değerini LCD ekranın 0. satırının 10. sütununa yazdırıyoruz ve " C" ile birlikte gösteriyoruz.

9. `displayHumidity()` fonksiyonunu çağırarak nem değerini LCD ekranın 1. satırının 6. sütununa yazdırıyoruz ve "%" ile birlikte gösteriyoruz.

10. Son olarak, `delay(2000)` ile 2 saniye gecikme ekleyerek ölçümlerin arasında zaman veriyoruz.


Eğer LCD ekranınız I2C arabirimine sahip değilse, doğrudan bağlantı yapmanız gerekecektir. Bu durumda LCD ekranını Arduino Uno'ya bağlamak için aşağıdaki adımları izleyebilirsiniz:

1. LCD ekranınızın pimlerini kontrol edin. Genellikle VCC, GND, RS, E, D4, D5, D6 ve D7 gibi pimler bulunur.

2. Arduino Uno'da LCD ekranı bağlamak için belirli pinleri kullanmamız gerekecektir. Bu pinleri projenizin ihtiyaçlarına göre ayarlayabilirsiniz. Örnek olarak, aşağıdaki bağlantıları kullanabilirsiniz:

   - LCD ekranının VCC pimini Arduino'nun 5V pinine bağlayın.
   - LCD ekranının GND pimini Arduino'nun GND pinine bağlayın.
   - LCD ekranının RS pimini Arduino'nun belirlediğiniz bir dijital pinine bağlayın.
   - LCD ekranının E pimini Arduino'nun belirlediğiniz bir dijital pinine bağlayın.
   - LCD ekranının D4, D5, D6 ve D7 pinlerini Arduino'nun belirlediğiniz dijital pinlerine bağlayın.

3. LCD ekranını kullanabilmek için `LiquidCrystal` kütüphanesini yükleyin. Bunun için Arduino IDE'de "Kütüphane Yöneticisi"ni açın, arama çubuğuna "LiquidCrystal" yazın ve gelen sonuçlardan doğru kütüphaneyi seçerek yükleyin.



Bu adımları takip ederek, I2C arabirimine sahip olmayan LCD ekranınızı Arduino Uno'ya doğrudan bağlayabilir ve kullanabilirsiniz. Bağlantıları doğru bir şekilde yapmak ve kodunuzu doğru ayarlamak önemlidir.

# DHT11 Connections

1. DHT11 sensörü, üç pinden oluşur: VCC, GND ve SIGNAL (veri). 
   - VCC pini 5V güç kaynağına bağlanmalıdır.
   - GND pini Arduino'nun GND (toprak) pinine bağlanmalıdır.
   - SIGNAL pini, veri iletimi için Arduino'ya bağlanacak pin olacaktır.


2. Arduino Uno'nun 2. pini, DHT11 sensöründeki SIGNAL piniyle doğrudan bağlantılı olmalıdır.

Bu şekilde DHT11 sensörü doğru bir şekilde Arduino Uno'ya bağlanacaktır. Daha sonra, kodu çalıştırarak sensörden sıcaklık ve nem verilerini okuyabilirsiniz.




