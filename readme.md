<p align=center>
<img width="700" alt="giabalanaipico_logo" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/giabalanaipico_logo.png">
</p>

![giabalanaipico overview](https://github.com/3araht/giabalanaipico/blob/main/pictures/giabalanaipico_overview.jpg)

# giabalanaipico キーボード
giabalanaipico キーボードは [giabalanai](https://github.com/3araht/giabalanai) の姉妹品で、蛇腹の無いシンプルデザインのクロマチックボタンアコーディオンチックな MIDI キーボード （左手側 60 ベース + 右手側 62 鍵 ） です。  
giabalanai では Pro Micro という頭脳を使っていましたが、 giabalanaipico では Raspberry Pi Pico を使っています。  
giabalanaipico は PC / Mac / iPad / iPhone / Android で動作します(ファームウェアの書き込み & キー配列の初期化・更新にだけ PC / Mac が必要です)。

コネクタが Lightning タイプの iPad や iPhone で使う場合、下記に示すアダプターを使って電源供給しながら使えることを確認しています。
iPad や iPhone で giabalanaipico を使う場合には電源が必要ですので、必ず "[Lightning - USB 3カメラアダプタ](https://www.apple.com/jp/shop/product/MK0W2AM/A/)" をお使いください。
"Lightning - USBカメラアダプタ" では電源供給ができません。

なお、USB-C タイプの iPad Air 4th Gen で試したところ、電源供給なしに問題なく動作させることができました。

ロータリーエンコーダは長押しでモード切り替えレイヤーへ。短押しでミュート切り替え、回転させるとシステム音量の調整に使用することが可能です。

# 外観および使用例
姉妹品の [giabalanai](https://github.com/3araht/giabalanai) の使用例はこちら。  
これらの動画 ([video1](https://youtu.be/EOIqms4lRcw), [video2](https://youtu.be/-KNHJdDH71s)) をご覧ください。


[こちら](https://youtu.be/hDas2LR00f4) は蛇腹談義のジングル(https://www.youtube.com/watch?v=WSVRJk6kDiM) を弾こうとしている様子です。

[私の YouTube チャンネル](https://www.youtube.com/channel/UC0zYtYMoxb0P7S8DPAkl0zA/) も併せてご覧ください。

# キーボードキット
## ラインナップ
giabalanai シリーズには全部で6通りのバリエーションがございます。

|名前               | 説明                                                 |
|------------------|------------------------------------------------------|
| giabalanai       | 左手側が60鍵（伴奏用）右手側が62鍵盤（C-System）＋ロータリーエンコーダーが取り付け可能なモデル。|
| giabaLEnai       | giabalanai の右手側だけ版|
| giabaRInaix2     | giabalanai の左手側のキーボードを2つ連結したモデル。ロータリーエンコーダーはありませんが、120キー全てが独立しているので自由にキー配置を変更できます（ソフト変更必要）。バンドネオン奏者の方、クロマトーン を演奏される方にはお勧め。|
| giabaRInai       | giabalanai の左手側だけ版。giabaLEnai 持っているけどやっぱり左手側も欲しいという方向け。|
| giabalanaipico   | giabalanai の Raspberry Pi Pico 版。右手側鍵盤が全て独立しました。また、レジスタスイッチも使えるようになりました。|
| giabaLEnaipico   | giabalanaipico の右手側だけ版|

なお、左右のキーボードを TRRS ケーブルで接続するのですが、 giabalanai (Pro Micro 版) と giabalanaipico (Raspberry Pi Pico 版) の混在（例：右手は giabalanai のキーボード、左手は giabalanaipico のキーボードを TRRS ケーブルで繋ぐこと）はお止めください。
Pro Micro は 5 V, Raspberry Pi Pico は 3.3 V で動作しているのでシリアル信号線のレベルミスマッチが生じて壊す恐れがある & そもそもファームウェアが別物なので正常に動作しないと思います（壊したくないので試せてませんが）。  

giabalanaipico キーボードキットはBOOTHでお求めいただけます。  
[BOOTH 販売ページへのリンクはこちら](https://3araht.booth.pm/)。

# ファームウェア

giabalanaipico は QMK firmware を使っています。  
ただし 2021/11/13 現在 正式に Raspberry Pi に対応していません。  
[せきごん さんの開拓された手法](https://scrapbox.io/self-made-kbds-ja/RP2040対応のQMK(非公式)を動かす) を使わせていただいております。  

giabalanaepico のソースコードは[こちら](https://github.com/3araht/giabalanaipico/blob/main/temp/qmk_firmware/keyboards/giabalanaipico) からダウンロード下さい。

もしくは、こちらのコンパイル済の [uf2 file](https://github.com/3araht/giabalanaipico/blob/main/giabalanaipico_led_uf2) をお使いください。

# ビルドガイド

[日本語ビルドガイド](https://github.com/3araht/giabalanaipico/blob/main/docs/build.md)

# コンタクト先:
Twitter, YouTube, Instagram はじめました。  
http://twitter.com/3araht  
https://www.youtube.com/channel/UC0zYtYMoxb0P7S8DPAkl0zA/  
https://www.instagram.com/3araht/  


## その他
#### giabalanai の名前の由来
アコーディオンの蛇腹が無いところから来ています（ジャバラナイ）。  
giabaLEnai （ジャバレナイ） は蛇腹に加えて左手側キーボード（LEft）がないこと、giabaRInai （ジャバリナイ）は右手側キーボード（RIght）がないこと、giabaRInaix2 は giabaRInai の2つ版、ということを示しています。  
giabalanaepico や giabaLEnaipico は Raspberry Pi Pico 版です。

一応先祖はイタリア出身という設定なので、イタリア語表記を使っています。
そのため、 *jabaranai* ではなく giabalanai になっています。

giabalanaipico の pico は Raspberry Pi Pico の pico に由来しています。  
<!--- not jabaranai but giabalanai ジャバラナイの名前の由来 -->


![tactsw](https://github.com/3araht/giabalanaipico/blob/main/pictures/right_side_tactsw.jpg)

![tactsw2](https://github.com/3araht/giabalanaipico/blob/main/pictures/right_side_tactsw2.jpg)

![tactsw3](https://github.com/3araht/giabalanaipico/blob/main/pictures/left_side_tactsw.jpg)

# giabalanaipico keyboard
giabalanaipico keyboard is a simple-design Chromatic Button Accordion-ish MIDI keyboard (60 bass + C-system 62 keys = 38 notes) that doesn't have bellows.
giabalanaipico works with PC, Mac, iPad, iPhone, and Android devices (PC or Mac is required during flashing the fimrware and initializing / adjusting the keymap ) .

When using it with iPad or iPhone, it works when the below adapter is used with a power supply. The power supply is necessary to use giabalanaipico on iPad and iPhone. Make sure to use "[Lightning to USB 3 Camera Adapter](https://www.apple.com/shop/product/MK0W2AM/A/)", not "Lightning to USB Camera Adapter."  


It would work with [USB-C Digital AV Multiport Adapter](https://www.apple.com/shop/product/MUF82AM/A/) for the USB-C type iPads.

A rotary encoder can be used to change the settings of giabalanaipico by long-pressing the push-button of the encorder, mute/unmute by clicking, and adjusting the system volume of your computer by rotating the encoder.


# How it looks & how it works
Check these short videos ([video1](https://youtu.be/EOIqms4lRcw), [video2](https://youtu.be/-KNHJdDH71s)) to see how it looks & how it works.  
Those are actually [giabalanai](https://github.com/3araht/giabalanai) and not giabalanaipico, but you'll get the picture.

Here's another [video](https://youtu.be/hDas2LR00f4), trying to play (pardon my poor playing skills) a theme song of Giabala-Dangi (https://www.youtube.com/watch?v=WSVRJk6kDiM).

Check [my YouTube channel](https://www.youtube.com/channel/UC0zYtYMoxb0P7S8DPAkl0zA/) for more videos.

# Keyboard kit
## Lineup
There are total 6 types in giabalanai series:

|Name               | Notes                                               |
|------------------|------------------------------------------------------|
| giabalanai       | 60 keys on the left-hand side for playing chords and 62 keys ＋ optional rotary encoder on the right-hand side for playing the melody (C-System)|
| giabaLEnai       | The right-hand side only version of giabalanai |
| giabaRInaix2     | Two pcs of the left-hand side of giabalanai. Rotary Encoder is not applicable. All 120 keys are isolated, so there is more flexibility for customizing the key layout (software modification is required). Bandoneon and Chromatone players might be interested in this model.|
| giabaRInai       | The left-hand side only version of giabalanai. For our friends who have giabaLEnai but want to have the left-hand side later on.|
| giabalanaipico   | Raspberry Pi Pico version of giabalanai. All keys on the right side keyboard are now independent. Register switches are now available. |
| giabaLEnaipico   |  The right-hand side only version of giabalanaipico |

TRRS cable is used to connect left side keyboard and right side keyboard. Please refrain from mixing up giabalanai (Pro Micro edition) and giabalanaipico (Raspberry Pi Pico edition), for example: connecting the right hand side of giabalanai with the left hand side of giabalanaipico with a TRRS cable.
Pro Micro works with 5 V while Raspberry Pi Pico with 3.3 V, and furthermore, the firmware itself is different and it wouldn't work at all. I haven't tested it and I won't since I'm scared damaging something.

The keyboard kits are available from [Yushakobo](https://yushakobo.jp/shop/consign_giabalanaipico/), or from [BOOTH](https://3araht.booth.pm/).  

Click [here](https://www.tenso.com/en/static/lp_shop_booth) for BOOTH overseas shipping!

All 6 models are available from [BOOTH](https://3araht.booth.pm/).

# Firmware

The giabalanaipico uses QMK for its firmware. However, as of Nov 13th, 2021, QMK does not fully support Raspberry Pi...  
Thanks to sekigon-gonnoc, [the method sekigon-gonnoc has built](https://scrapbox.io/self-made-kbds-ja/RP2040対応のQMK(非公式)を動かす) is used.  
Please download codes from [here](https://github.com/3araht/giabalanaipico/blob/main/temp/qmk_firmware/keyboards/giabalanaipico).

Or, use this pre-compiled [uf2 file](https://github.com/3araht/giabalanaipico/blob/main/giabalanaipico_led_uf2) for your convenience.

# Build Guide

[Build Guide in Japanese](https://github.com/3araht/giabalanaipico/blob/main/docs/build.md)  
Try [Google Translated guide](https://translate.google.com/translate?sl=ja&tl=en&u=https://github.com/3araht/giabalanaipico/blob/main/docs/build.md) for your language preferences. Trust me, it works quite well, more than expected.


# Contact
If you need any help, you know where to find me.  
http://twitter.com/3araht  
https://www.youtube.com/channel/UC0zYtYMoxb0P7S8DPAkl0zA/  
https://www.instagram.com/3araht/  


## Miscellaneous
#### Origin of the name: giabalanai
When you pronounce giabalanai, it sounds like "蛇腹無い" in Japanese = *bellows-less*, which represents the keyboard.  
Much easier for others: giabaLEnai = not only bellows-less but missing LEft-hand side, giabaRInai = not only bellows-less but missing RIght-hand side, and two sets of giabaRInai is giabaRInaix2.  
giabalanaipico is a Raspberry Pi Pico version of giabalanai.  

Well, the ancestor of this keyboard is located in Italy ;-) so the Italian spelling method is used.
That's why it is not *jabaranai* but giabalanai.
<!--- not jabaranai but giabalanai ジャバラナイの名前の由来 -->
