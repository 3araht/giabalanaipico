# giabalanaipico Build Guide
**一度すべて読んでから組み立てることをお勧めします。**
giabalanai と giabalanaipico の違い：

- giabalanai は ProMicro、 giabalanaipico は Raspberry Pi Pico を使います。
- giabalanai は SK6812mini に対応, giabalanaipico は SK6812mini-E に対応
- giabalanaipico の右手側の鍵の全てが独立しているので、KEYMAP などで独立したキー配列に変更することができます。

## 0 ##
## パーツの確認、各部品の実装面の整理 ###
### キット付属品

| パーツ名 |  個数  |  備考  |
|--------|-------|-------|  
|左手側基板|1枚|キーが平行四辺形に5行12列配置されているもの。|
|右手側基板|1枚|キーが上から12列、13列、12列、13列、12列配置されていて、右端にはエンコーダーが配置されているもの。|
|ボトムプレート|2枚|左手側基板も右手側基板も同じボトムプレートを使います。|
|M2 スペーサー |20個|左右各10個|
|M2 ネジ|40個|左右各20個|
|クッションシール|10個|左右各5個|
|TRRSジャック|2個|左右の基板を繋ぐTRRSケーブル用|
|リセットスイッチ|2個|ファームウェアを書き込むときに使います。|
|ダイオード 1N4148|140個|左手側は60鍵 + タクトスイッチ10個、右手側は62鍵 ＋ タクトスイッチ7個 ＋ エンコーダ用1個|

### 別途用意いただく必要のあるもの

| パーツ名 |  個数  |  備考  |
|--------|-------|--------|  
|[Raspberry Pi Pico](https://shop.yushakobo.jp/products/raspberry-pi-pico)|2個||
|[コンスルー（20ピン 2.5 mm）](https://shop.yushakobo.jp/products/31?_pos=1&_sid=388c46575&_ss=r&variant=40815840067745)|4本|コンスルーを使えば、Raspberry Pi Pico を基板に取り付けるのに半田付けが不要になります。 Raspberry Pi Pico を実装する位置にキースイッチ等があるので、コンスルーがあると動作確認などで都度 Raspberry Pi Pico が付け外しできて便利です。|
|キースイッチ(CherryMX 互換品)|122個|左手側60個＋右手側62個。（5pinタイプ推奨）|
|MX対応キーキャップ|122個|1U、左60個＋右62個。|
|[TRRSケーブル](https://yushakobo.jp/shop/trrs_cable/)|1本|AUXケーブルとも呼ばれている3.5mmオーディオ用の4極ケーブル(左手側のLEDも発光させる場合は4極ケーブルが必須)。|
|MicroUSBケーブル|1本|データ通信ができるケーブルである必要がありますので、充電用のケーブルは使えません。Raspberry Pi Pico を認識しない場合は、ケーブルを確認してみてください。|

### [Optional]別途用意いただく必要のあるもの

| パーツ名 |  個数  |  備考  |
|--------|-------|-------|
|[ロータリーエンコーダ(ノブ付き)](https://yushakobo.jp/shop/pec12r-4222f-s0024/)|1個|右手側のキーボードに配置。押しボタン機能付きのものを選んでください（端子が上に2本（押しボタン用）、下に3本（エンコーダー用）生えてるやつ）。音量調整＋ミュート用のロータリーエンコーダを取り付ける場合は必要。長押し＋〇〇でレイヤー切り替えができますので、あったほうがよいと思います。|
|LED（SK6812mini-E）**注意: SK6812mini は使用できません。**|123個|2の「Backlight RGB LED」を使う場合に必要。左60個＋右62個＋エンコーダ用1個。難しい半田付けを伴うので、半田付け初心者の方はLEDなしで組み立てられることをお勧め致します。|
|[タクトスイッチ](https://shop.yushakobo.jp/collections/all-keyboard-parts/products/a0800ts-03-1)|〜17個|お好みで左最大10個、右最大7個実装可能です。レジスタスイッチやサスティンなどの機能を割り当てることができます。[秋月電子](https://akizukidenshi.com/catalog/goods/search.aspx?keyword=&maker=&goods=&number=TS-0606-F-N&name=&min_price=&max_price=&last_sdt=&sort=&style=T&search.x=0&search.y=0)にさまざまな色のものがございます。|
|[キーボードアクリルプレート giabalanai スイッチプレート・左手・3mm](https://shop.yushakobo.jp/collections/services-auto/products/keyboard_acrylic_plate?variant=39732120518817)|1枚|キースイッチが3pinタイプのものをお使いの場合には、このプレートがあるとキースイッチのアライメントが簡単になります。|
|[キーボードアクリルプレート giabalanai スイッチプレート・右手・3mm](https://shop.yushakobo.jp/collections/services-auto/products/keyboard_acrylic_plate?variant=39732118683809)|1枚|同上|

### オモテ面、裏面の実装物

**※ 部品の実装には順番があります。特に、Raspberry Pi Pico、キースイッチ、エンコーダ、の実装は最後になりますので先に実装しないよう注意ください。
実装の順番はこの後の手順に従ってください。**

基板の裏面には、ダイオードの実装場所やキーボード名が印字されています。

左手側 オモテ面  
<img width="700" alt="PCB" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/left_front_pcb_rpp_r02.jpg">

左手側 裏面  
<img width="700" alt="PCB" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/left_rear_pcb_rpp_r02.jpg">

右手側 オモテ面  
<img width="700" alt="PCB" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/right_front_pcb_rpp_r02.jpg">

右手側 裏面  
<img width="700" alt="PCB" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/right_rear_pcb_rpp_r02.jpg">


#### 裏面には次の部品を実装します
 - ダイオード
 - TRRSジャック
 - リセットスイッチ
 - Raspberry Pi Pico
 - LED[Optional]

#### オモテ面には次の部品を実装します
 - キースイッチ
 - エンコーダ
 - タクトスイッチ[Optional]


## 1
## ダイオードの取付け ##
キーの数が多いキーボードではMatrixという手法を使ってキーが押されたかどうか判断します。
キーが必ず1個ずつしか押されないと保証されているのであれば、このダイオードは不要なのですが、
和音を弾くことがあるので複数のキーを同時に押す場面が出てきます。
このとき、Matrixという手法で複数同時押しを正しく判断するためにこのダイオードが必要になります。
詳しい説明については、[こちら](https://docs.qmk.fm/#/how_a_matrix_works)などをご覧ください。

ダイオードには向きがあります。また、図のように足を曲げておきます。
ダイオードをつまんで両端の足を同時に曲げると図の右のように比較的ちょうどいい形になります。  
<img width="700" alt="diode" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/diode_bend.jpg">

キースイッチと干渉しないように、ダイオードは基板の裏面に実装します。
ダイオードの黒い線のほうが四角いフットプリント（Kと印字されている方, K はKathode（独）の頭文字らしいですが、黒（Kuro) の K で。）に合うように配置します。  
<img width="700" alt="diode" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/diode_align1.jpg">

足を曲げて基板に這わせてダイオードを仮止めします。  
<img width="700" alt="diode" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/diode_flatten.jpg">

オモテ面から見た図  
<img width="700" alt="diode" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/diode_flatten2.jpg">

オモテ面から半田付けします。  
<img width="700" alt="diode" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/diode_soldered.jpg">

足をニッパでカットします。足は勢いよく飛んで行くので、足を押さえながら切ると良いです。  
<img width="700" alt="diode" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/diode_feet_cut.jpg">

これを左手側基板は60箇所、右手側基板は39箇所半田付けします。

なお、下図のR1 には何も実装しません。  
<img width="700" alt="diode" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/R1_NoSolder_rpp_r02.jpg">


## 2 ##
## 基板の準備 ##
### 2.1 ###
### リセットスイッチとTRRSジャックの取付け ###
左右の基板共、白い四角い枠のシルクに沿って裏側に取り付けます。浮いたり曲がった状態で実装しないようにマスキングテープなどで予め仮止めしてから半田付けするとミスが少なくなります。  
<img width="700" alt="TRRS_ResetSW" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/TRRS_ResetSW_rpp_r02.jpg">

### 2.2 ###
### ジャンパーのショート ###
左手側の基板において、以下に示す部分のを半田でジャンパーします（合計2箇所）。これにより、1、右手側基板との通信が開通 2、左手側の Raspberry Pi Pico が左手側の基板と認識できるようになります。  
<img width="700" alt="Jumper" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/jumper_rpp_r02.jpg">  

また、4, でLEDを実装する場合は、左右の基板の以下もジャンパーします（合計3箇所）。これにより、LED データ線が開通します。  
<img width="700" alt="Jumper" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/LED_jumper_rpp_r02.jpg">  


## 3 ##
### 3.1 ###
### コンスルーを使った Raspberry Pi Pico の基板への取付け ###
白い四角い枠のシルクに沿って裏側にコンスルーを取り付けます。  
Raspberry Pi Pico も giabalanaipico の基板もコンスルーを半田付けせずに固定できるので、取り外しも簡単です。しかし、BOOTSELボタンを押したときに抜けてしまうことがあるので、Raspberry Pi Pico 側だけは半田付けすることをおすすめします。(基板＝PCB側は半田付けしなくても、コンスルーのピンがボトムプレートに押さえつけられるので抜けません。)  

コンスルーには向きがあります。小さな穴が空いている方を Raspberry Pi Pico 側とし、そちらを半田付けします。  
<img width="700" alt="Conthrough" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Conthrough01.jpg">  

基板裏面からこの写真のようにコンスルーを差し込みます。小さな穴がある方は Raspberry Pi Pico 側になるように、上にくるようにします。  
<img width="700" alt="Conthrough" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Conthrough02.jpg">  

Raspberry Pi Pico を裏にしてこの写真のように差し込みます。  
<img width="700" alt="Conthrough" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Conthrough03.jpg">  

オモテ面から見て、BOOTSEL ボタンが穴から見えたら、向きは正しいです。  
<img width="700" alt="Conthrough" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Conthrough04.jpg">  

では、半田付けをしていきます。コンスルーと Raspberry Pi Pico が浮かないように軽く押さえながらまずは1ピンだけ半田付けします。ここであまり強く押さえつけすぎてしまうと、コンスルーのピンが黒い樹脂部から抜けてしまうことがあるので、ピンは押さず、樹脂と基板、樹脂と Raspberry Pi Pico を押さえるようにします。    
<img width="700" alt="Conthrough" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Conthrough05.jpg">  

浮きが無いことを確認したら、四隅を半田付けして浮きがない状態で位置決めしてしまいます。  
<img width="700" alt="Conthrough" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Conthrough06.jpg">  

位置決めを終えたら、残りのピンの半田付けをしていきます。  
<img width="700" alt="Conthrough" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Conthrough07.jpg">  

基板（PCB）とコンスルーは半田付けしていないので、このように Raspberry Pi Pico を抜くこともできます。  
<img width="700" alt="Conthrough" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Conthrough08.jpg">  

Raspberry Pi Pico をオモテ面からみた様子。  
<img width="700" alt="Conthrough" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Conthrough09.jpg">  

Raspberry Pi Pico のUSBコネクタの逆側は何も半田付けしません。  
<img width="700" alt="Conthrough" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Conthrough10.jpg">  




**コンスルーを使わず、ピンヘッダを使う場合の注意点**  
ピンヘッダを使った実装はお勧めしませんが、ここではピンヘッダを使う場合の注意点を記します。  
最初に基板とピンヘッダだけを半田付けしてください。  
このとき、ピンヘッダの位置決めに Raspberry Pi Pico をはめ込んでおきます（しかし、Raspberry Pi Pico は半田付けしないように！！！）。  
Raspberry Pi Pico を半田付けしてしまうと、その裏にある LED や キースイッチが実装できなくなってしまいますので、
Raspberry Pi Pico の半田付けは6, が終わってから行います。  
Raspberry Pi Pico の半田付け後にその裏にある LED やキースイッチの半田付けのやり直しができないので、Raspberry Pi Pico の半田付けは LED やキースイッチの半田に問題ないことを十分確認してから半田付けしてください。  
（こういったこともあり、付け外しが可能なコンスルーの使用をお勧めしています。）

### 3.2 ###
### Firmwareの書き込み ###
Raspberry Pi Pico に giabalanaipico のファームウェアを書き込みます。  
左右用の Raspberry Pi Pico 両方に同じファームウェアを書き込みます。  

まず、
[giabalanaipico_led.uf2](https://github.com/3araht/giabalanaipico/blob/main/giabalanaipico_led.uf2) を ダウンロードします。  

Raspberry Pi Pico の BOOTSEL ボタンを押しながらUSBケーブルで PC/Mac と接続します。  
このことで、ブードローダ状態（＝ファームウェアを書き込める状態）になります。  
<img width="700" alt="Raspberry Pi Pico" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/RaspberryPiPico.jpg">
<img width="700" alt="Raspberry Pi Pico with USB cable" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/RaspberryPiPicoWithUSBcable.jpg">

すると、Raspberry Pi Pico を USB ドライブとして認識します。  
もし USB ドライブとして認識しない場合は、USB ケーブルが充電専用のものではなく、ちゃんとデータ通信が可能なケーブルかどうかご確認ください。
（充電器に付属のケーブルなどは、データ通信線が無いものが多いですのでご注意ください。）  

ダウンロードした giabalanaipico_led.uf2 をRaspberry Pi Pico のドライブにドラッグ＆ドロップします。  
これで Raspberry Pi Pico の書き込みは終わりです。  
(Raspberry Pi Pico を初めて使われる方は、手始めに LED の点滅＝通称「Lチカ」を試されると良いかもしれません。)  

なお、一度このファームウェアを書き込むと、リセットボタンを素早く2回押すとブートローダ状態になるようになっているみたいです。なんて便利！(後述しますが、このファームウェア作成を可能にしてくださった せきごん さん様様です)。  

同様にして、2つ目の Raspberry Pi Pico にもファームウェアを書き込んでおきます。  


### 3.3 ###
### REMAP を使った初期キー配列の初期化 ###
[REMAP](https://remap-keys.app/) でキー配列を自由に変更することが可能です。  
ファームウェアを書き込んだ Raspberry Pi Pico をPC/Mac に接続した状態で Chrome ブラウザを使って上記リンクにアクセスしてください(残念ながら、iPhone、iPad、タブレットなどのブラウザでは非対応)。  
キー配列をデフォルトのままで使用する場合も、最初の1回は以下の手順でキー配列の初期化を行ってください。  

したの部分をクリック。  
<img width="700" alt="REMAP reset" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/giabalanaipico_REMAP_reset1.png">  

"Reset Keymap" を選択。  
<img width="700" alt="REMAP reset" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/giabalanaipico_REMAP_reset2.png">  

本当に初期化していいですか？と聞かれるので"Yes"します。    
<img width="700" alt="REMAP reset" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/giabalanaipico_REMAP_reset3.png">  

完了すると、右上にその旨表示されます。これで、初期値のキー配列を使用できるようになります。    
<img width="700" alt="REMAP reset" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/giabalanaipico_REMAP_reset4.png">  

#### このファームウェアでの REMAP の挙動について ####
原因不明ですが、 今回の Raspberry Pi Pico のファームウェアでは、REMAP 機能の1つである "Test Matrix mode" が動作しません。 ちゃんとキーを認識して音も出るのですが、"Test Matrix mode" でそのキーが押されたという判定になりませんでした。6, で示すように、キースイッチの動作確認は実際に音がでるかどうかで判断します。  

## 4 ##
## Backlight RGB LEDの取付け[Optional] ##
***LED を取り付けない方は 5, に進んでください。***  

イメージトレーニングが重要なので、まずは ”SK6812mini-E はんだ付け” で半田付けの様子を紹介している動画をチェックしてみてください。  
また、以下を使うことが成功の鍵となります。  
- 温度調整機能付き半田ごてで温度を240℃程度に設定する（白光 FX-600 の場合、270℃の1つ低い温度）。
- 融点の低い 鉛入り半田（共晶半田）を使う

半田ごての温度設定  
<img width="700" alt="SolderIronTemperature" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/FX-600A_240degC.jpg">  

こちらの[SK6812mini-E 半田付け事例](https://youtu.be/zy0iFEmkFuE?t=607) も参考にしていただけたら幸いです。

バックライト用のチップLED(SK6812mini-E)はPCBの裏面から実装します。向きに注意して穴に入れてください。  

LED はデータを直列に伝送する都合上、最上行はオモテ面からみて左から右、2行目は右から左、3行目はまた左から右に…と並んでいます（右手側の場合）。  
LED の実装はこの順番に進めて、すこし実装したら LED の点灯確認、をすると効率よく進められると思います。  
（giabalanai とはロータリーエンコーダー部分のLEDの並びが違いますので、giabalanai 組み立てられた方はその点をご留意ください。）  
<img width="700" alt="RGB_LED" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/LED_serial_rpp.jpg">

このため、偶数行と奇数行のLEDの向きが違うので十分ご注意ください。
半田付けが軌道に乗った矢先に向きを間違えがちです。
その時のショックと言ったら。。。（経験者談）。下図のように、LEDの切り欠きと三角マークを合わせます。  
<img width="700" alt="RGB_LED" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/SK6812mini-E_alignment.jpg">

温調半田ごてを使い、約240℃で半田付けします。温度が高いとLEDが壊れますので注意してください。
温調できない半田ごてではすぐに焦げます＆壊れます（これも経験者談）。

LEDは、右手側 の Raspberry Pi Pico から右手側基板の左上のLEDから直列繋ぎにデータを伝達し、右手側基板上の63個のLEDを通過したデータはTRRSケーブルを通じて左手側基板上面からみて右上のLEDから直列繋ぎにデータを伝達します。  
***ですから、左手側の基板の LED の動作チェックは、右手側基板の LED の実装が終わり、TRRSケーブルで左右の基板を接続した状態で行います。***

LEDの情報は直列に伝送されますので、接続が途切れてしまうと正しくLEDが光らなくなります。

## 5 ##
## 基板へのスペーサーのネジ止め ##
スペーサーを左右の基板の裏面にネジで固定します（ネジをオモテ面に挿し、スペーサーが裏面にくるようにします）。  
キースイッチを半田付けした後にはネジを挿入することが難しい箇所があるため、キースイッチを半田付けする前に基板にネジを固定します。  
ただし、半田ごてがスペーサーに触れてしまうとスペーサーが溶けてしまうので、半田付けする際には十分ご注意ください。  
<img width="700" alt="switch" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Spacer_rpp_r02.jpg">

## 6 ##
## キースイッチの取付けと、タクトスイッチ（Option）、エンコーダ（Option）の取付け ##
**スイッチを取り付ける前に部品の取付けや半田付けができているか確認します。**  
（1 のダイオードは必ず済ませておいてください。また、コンスルーを使わない場合（非推奨）は、事前の動作確認ができませんので、半田付けを念入りに済ませて置いてください。）  

**動作確認する際には、①左右の基板両方に uf2 ファイル書き込み済の Raspberry Pi Pico を実装し、②左右の基板を繋ぐTRRSケーブルを奥までしっかり挿して接続してから、③USBケーブルを右手側基板に挿して実施してください。**
（写真は giabalanai のものなので多少違います。ご了承ください）  
<img width="700" alt="switch" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Keysw_test.jpg">

キースイッチをオモテ側からしっかり奥まで差し込みます。このとき、端子が曲がっていると実装穴に端子が入らないので注意してください。1行ずつキースイッチをしっかり差し込んでから半田付けしていった方が差し込み不良は減らせると思います。  
（写真は giabalanai のものなので多少違います。ご了承ください）  
<img width="700" alt="switch" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Keysw_front_r02.jpg">  
<img width="700" alt="switch" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Keysw_rear_r02.jpg">


ロータリーエンコーダー、タクトスイッチを実装する場合は実装します。  
<img width="700" alt="RotaryEncorderTactSW" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/right_side_tactsw.jpg">


## 7 キーキャップ 取り付け ##
キーキャップをキースイッチに取り付けて行きます。キーキャップによっては、上下逆には刺さっても、左右方向を90度回転させて上下方向にすると刺さらないものもありますので、とても固い場合は、90度回転していないか確認してみてください。  
<img width="700" alt="keycaps" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/giabalanaipico_keycaps_r02.jpg">


## 8 ##
## チェックポイント ##
簡単なチェック項目を挙げます。参考になれば幸いです。

【全体】
- Raspberry Pi Pico は左右の基板共にしっかり基板に刺さっている。
- Raspberry Pi Pico のピンと基板のピンは一致させた状態で接続できている（Raspberry Pi Pico の上下の向き確認）。
- USB ケーブルは通信可能なものを使っている（充電器の付属品などは要注意）。
- Raspberry Pi Pico にファームウェアを書き込んである（左右同じHEXファイルを書き込みます）。
- TRRS ケーブルはしっかり奥まで刺さっている（少しきついのでこれが問題となりがちです。ご注意ください。）
  また、TRRSケーブル内に 5V と GND 線が走っており、電源投入中に抜き差しするとショートする恐れがあるので、活線挿抜はお控えください。
- MIDI機器に対応したソフトを起動している。
- USBケーブルは右手側のキーボードに接続されている。**このキーボードでは、右手側がマスターとなっていますので、USBケーブルは必ず右手側に接続してください。**
- 半田付けに問題はないか（ダイオードの向き、赤目、富士山、など）。

【Backlight RGB LED編】  
- テスター（マルチメータ）をお持ちの場合は、＋端子を5Vに、−端子をGND、またはその逆、 に当てて ダイオード測定してみてください。
  0.6 V 〜 2 V くらい表示されれば正常です。
- LED の向きが正しいか(オモテ側からみて、小さな黒い点の向きが揃っているか。列ごとに向きが違うので注意)。
- 4つの端子が基板にしっかり半田付けできているか。数が多いので、数個半田が甘かった、ということはよくあります。
- あるところから先の LED が全く光らない場合は、その境界の LED の信号線で半田不良 or LED 破損の可能性があります。
  LED の並びについては、上記 2 Backlight RGB LED の取付け[Optional] をご覧ください。
- あるところから先の LED の光り方が変な場合は、その境界の LED の電源線（5V か GND）の半田不良 or LED 破損の可能性があります。
- LED は光るものの、他の LED に比べて暗い場合は、その LED が半田ごてに熱でやられている可能性があります。R,G,Bのうち1つが光っていない、という壊れ方もあるようですので、色を変えて確認することをお勧めします。

また、遊舎工房さんの[サポートサイト](https://yushakobo.zendesk.com/hc/ja)が参考になると思います。併せてご覧ください。


## 9 ##
## ボトムプレートの組み立て ##
全てのキースイッチが正しく動作するのを確認したら、左右の基板に取り付けたスペーサーにボトムプレートを固定します。
ボトムプレートの図の赤丸の位置 10 箇所に M2 のねじでを挿入して固定します。  
<img width="700" alt="spacer" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/BottomPlate_r02.jpg">  

ネジ止めは、たすき掛けで均一に締めつけますが、強く締めつけすぎないようにします。

緑丸の位置にクッションシールを取り付けます。  
<img width="700" alt="feet" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/Cushon_r02.jpg">

#### お疲れ様でした。以上で giabalanaipico キーボードの完成です！

## 10 ##
## 付録 ##
### 10.1 ###
### コーディングされる場合の手順 ###
2021/11/7現在、QMK はまだ Raspberry Pi Pico に完全対応していません。  
暫定策として、せきごんさんが pico-sdk を使った方法を開拓してくださいました。  
[せきごんさんのサイト](https://scrapbox.io/self-made-kbds-ja/RP2040%E5%AF%BE%E5%BF%9C%E3%81%AEQMK(%E9%9D%9E%E5%85%AC%E5%BC%8F)%E3%82%92%E5%8B%95%E3%81%8B%E3%81%99)   
この場を借りて せきごん さんに改めて感謝致します。  
なお、冒頭に書かれているように、QMK公式が対応するまでの暫定版、という位置付けらしいです。現状開示いただいている状態での活用を心がけています。せきごんさんに迷惑がかからないように、問い合わせなどはしないようにしましょう。  
また、私も手探り状態で試してうまく行った事例を紹介してますが、もしかしたら間違ったやり方をしている可能性があります。ここで紹介する手順は、あまり自信が無い状態での情報シェアであることはご留意ください。  
(コンパイル済みのものは問題無く動いているので大丈夫だと思うのですが。。。)

#### 10.1.1 ####
#### コーディングされる場合の環境準備 ####
まず、 [せきごんさんのサイト](https://scrapbox.io/self-made-kbds-ja/RP2040%E5%AF%BE%E5%BF%9C%E3%81%AEQMK(%E9%9D%9E%E5%85%AC%E5%BC%8F)%E3%82%92%E5%8B%95%E3%81%8B%E3%81%99)に従って、 pico-sdk や せきごんさん が準備された qmk_firmware を準備します。  
「前準備」と「セットアップの確認」まで進めます。  
尚、pico-sdk の環境がちゃんと準備できているか確認するためにも、[Raspberry Pi Pico のドキュメント](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)を参考に、Lチカ のサンプル(blink というサンプルです)を使って確認しておくと良いと思います。  

その後、qmk_firmware のフォルダでsubmodule の準備をしておきます。  
```
$ make git-submodule
```

次に、giabalanaipico のソースコードを以下のリンクからダウンロードして、 qmk_firmware/keyboards フォルダに giabalanaipico フォルダごと貼り付けます。  
[こちら](https://github.com/3araht/giabalanaipico/blob/main/temp/qmk_firmware/keyboards/giabalanaipico)のソースコードをお使いください。  

サスティン問題回避  
MIDIソフトによっては、同じ音を重ねて鳴らしたときにその音にUSBケーブルを抜き差しするまでサスティンがかかってしまう現象がありました。
~~対策方法がわかりましたので、それを適用します（こちらも pull request 中。正式に採用されるまでの暫定対策）。
2020/10/5 pull request が メインブランチにマージされました。最新のソフトを clone いただければOKです。~~  
2021/04/13 残念ながら、2021/3/25 の process_midi.c の更新により、再びこの問題が復活しています。
コンパイル前に以下のコマンドでエンバグ前のコードを引っ張り出してコンパイルしてください。
```
$ git checkout c66df16 quantum/process_keycode/process_midi.c
```

#### 10.1.2 ####
#### コンパイル ####
qmk_firmware のフォルダで以下のコマンドを実行すると、
```
$ make giabalanaipico:led:uf2
```

Raspberry Pi Pico をブートローダ状態にしたときにドラッグ＆ドロップでファームウェアを書き込める uf2 ファイルが出来上がる。。。はずなのですが、
以下のようなエラーが出るかもしれません。(私の環境では出ました。)  
```
Assembler messages:
Fatal error: can't create .build/obj_giabalanaipico/src/bs2_default.o: No such file or directory
make[1]: *** [.build/obj_giabalanaipico/src/bs2_default.o] Error 1
make: *** [giabalanaipico:led:uf2] Error 1
Make finished with errors
```

その場合は、以下のようにシンボリックリンクを張るとコンパイルが通るようになりました。  
```
(qmk_firmware のフォルダにいる状態から)
$ make rp2040_example:default
cd .build/obj_giabalanaipico
ln -s ../obj_rp2040_example/src .
cd -
```

このリンクが張れるようにするには、その前に rp2040_example のコンパイルを実施しておく必要があります. 以下はそのためです。  
```
$ make rp2040_example:default
```

（ちょっと原因がわかっていないのですが、最初は obj_rp2040_example/src が生成されていたのですが、何度かやっていくうちに生成されなくなってしまいました。。。もしobj_rp2040_example/src が生成されない場合は、qmk_firmware のクローンからやり直すとうまく行くかもしれません。）

次に以下のエラーがでてきたら、  
```
Traceback (most recent call last):
  File "<path-to-your-qmk-folder>/qmk_firmware/./util/uf2conv.py", line 292, in <module>
    main()
  File "<path-to-your-qmk-folder>/qmk_firmware/./util/uf2conv.py", line 258, in main
    with open(args.input, mode='rb') as f:
FileNotFoundError: [Errno 2] No such file or directory: 'giabalanaipico_led.bin'
make[1]: *** [uf2] Error 1
make: *** [giabalanaipico:led:uf2] Error 1
```

tmk_core/pico.mk を少し修正します。  

```
./util/uf2conv.py -f 0xe48bff56 -b 0x10000000 -o $(TARGET).uf2 $(TARGET).bin
->
./util/uf2conv.py -f 0xe48bff56 -b 0x10000000 -o $(TARGET).uf2 $(BUILD_DIR)/$(TARGET).bin
```

これでコンパイルが通るようになり、 uf2 ファイルが出来上がったと思います。  
ワーニングはまあまあ出てきます。が、とりあえずそのままで動きました。  

なお、ファームウェアの書き込みですが、以下のコマンドを実装するときに Raspberry Pi Pico をブートローダ状態にしておくと、自動で uf2 ファイルを Raspberry Pi Pico に書き込んでくれました。  
```
$ make giabalanaipico:led:uf2
(実行後、長いコンパイルの後、)
Flashing /Volumes/RPI-RP2 (RPI-RP2)
Wrote 130560 bytes to /Volumes/RPI-RP2/NEW.UF2.
```

#### 10.1.3 ####
#### 初期キー配列の初期化 ####
ファームウェアを書き込んだ後は、[REMAP を使った初期キー配列の初期化](#33) を参考にしてキー配列を初期化してください。  

### 10.2 ###
#### layers ####
音符のレイアウト一覧  
<img width="700" alt="Layer" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/20211128_giabalanaipico_layers.png">    

エンコーダボタン長押ししたときの様子 Function(FN) Layer  
<img width="700" alt="Layer" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/20211128_giabalanaipico_FN_layer.png">   




USBケーブルを左側のキーボードに接続したときにはQWERTY配列がデフォルトとなるようにしました。
つまり、いつも通り右手側のUSBに接続すればアコーディオン配列がデフォルト、左手側のUSBに接続すればタイピング用のQWERTY配列がデフォルト、という使い方ができるようになりました。
なお、デフォルトがQWERTY、というだけて、その後レイヤーを切り替えればアコーディオン配列としても使えます。  
（左手側にUSBケーブルを繋ぐと、どうやら LED は正しく光らないようです。予めご了承ください。）  