<p align=center>
<img width="700" alt="giabalanaipico_logo" src="https://github.com/3araht/giabalanaipico/blob/main/pictures/giabalanaipico_logo.png">
</p>

![giabalanaipico overview](https://github.com/3araht/giabalanaipico/blob/main/pictures/giabalanaipico_overview.jpg)

# giabalanaipico キーボード
giabalanaipico キーボードは蛇腹の無いシンプルデザインのクロマチックボタンアコーディオンチックな MIDI キーボード （60 ベース + C-system 62 鍵 = 38 音） です。
giabalanaipico は PC / Mac / iPad / iPhone / Android で動作します。

コネクタが Lightning タイプの iPad や iPhone で使う場合、下記に示すアダプターを使って電源供給しながら使えることを確認しています。
iPad や iPhone で giabalanaipico を使う場合には電源が必要ですので、必ず "[Lightning - USB 3カメラアダプタ](https://www.apple.com/jp/shop/product/MK0W2AM/A/)" をお使いください。
"Lightning - USBカメラアダプタ" では電源供給ができません。

USB-C タイプの iPad の場合は [USB-C Digital AV Multiportアダプタ](https://www.apple.com/jp/shop/product/MUF82ZA/A/)をお使いください。

ロータリーエンコーダは長押しでモード切り替えレイヤーへ。短押しでミュート切り替え、回転させるとシステム音量の調整に使用することが可能です。

# 外観および使用例
姉妹品の giabalanai の使用例はこちら。  
これらの動画 ([video1](https://github.com/3araht/giabalanai/blob/main/videos/giabalanai_keyboard.mp4), [video2](https://github.com/3araht/giabalanai/blob/main/videos/62buttons_38notes.mp4)) をご覧ください。

[こちら](https://github.com/3araht/giabalanai/blob/main/videos/giabala_dangi_ep.16_theme_song_feat.Mr.Seto.mp4) は蛇腹談義のジングル(https://www.youtube.com/watch?v=WSVRJk6kDiM) を弾こうとしている様子です。

[私の YouTube チャンネル](https://www.youtube.com/channel/UC0zYtYMoxb0P7S8DPAkl0zA/) も併せてご覧ください。

# キーボードキット
## ラインナップ
全部で5通りのバリエーションがございます。

|名前               | 説明                                                 |
|------------------|------------------------------------------------------|
| giabalanai       | 左手側が60鍵（伴奏用）右手側が62鍵盤（C-System）＋ロータリーエンコーダーが取り付け可能なモデル。|
| giabaLEnai       | giabalanai の右手側だけ版|
| giabaRInaix2     | giabalanai の左手側のキーボードを2つ連結したモデル。ロータリーエンコーダーはありませんが、120キー全てが独立しているので自由にキー配置を変更できます（ソフト変更必要）。バンドネオン奏者の方、クロマトーン を演奏される方にはお勧め。|
| giabaRInai       | giabalanai の左手側だけ版。giabaLEnai 持っているけどやっぱり左手側も欲しいという方向け。|
| giabalanaipico   | giabalanai の Raspberry Pi Pico 版。右手側鍵盤が全て独立しました。また、レジスタスイッチも使えるようになりました。|
| giabaLEnaipico   | giabalanaipico の右手側だけ版|

giabalanaipico キーボードキットはBOOTHでお求めいただけます。  
[BOOTH 販売ページへのリンクはこちら](https://3araht.booth.pm/)。

# ファームウェア

giabalanaipico は QMK firmware を使っています。

[こちら](https://github.com/3araht/giabalanaipico/blob/main/temp/qmk_firmware/keyboards/giabalanaipico) からベータ版をダウンロード下さい。

もしくは、こちらのコンパイル済の [uf2 file](https://github.com/3araht/giabalanaipico/blob/main/giabalanaipico_led_uf2.zip) をお使いください。

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
giabaLEnai （ジャバレナイ）　は蛇腹に加えて左手側キーボード（LEft）がないこと、giabaRInai （ジャバリナイ）は右手側キーボード（RIght）がないこと、giabaRInaix2 は giabaRInai の2つ版、ということを示しています。  
giabalanaepico や giabaLEnaipico は Raspberry Pi Pico 版です。

一応先祖はイタリア出身という設定なので、イタリア語表記を使っています。
そのため、 *jabaranai* ではなく giabalanai になっています。
<!--- not jabaranai but giabalanai ジャバラナイの名前の由来 -->


![giabalanai lighting](https://github.com/3araht/giabalanai/blob/main/pictures/giabalanai_lighting2.jpg)

# giabalanaipico keyboard
giabalanaipico keyboard is a simple-design Chromatic Button Accordion-ish MIDI keyboard (60 bass + C-system 62 keys = 38 notes) that doesn't have bellows.
giabalanaipico works with PC, Mac, iPad, iPhone, and Android devices.

When using it with iPad or iPhone, it works when the below adapter is used with a power supply. The power supply is necessary to use giabalanaipico on iPad and iPhone. Make sure to use "[Lightning to USB 3 Camera Adapter](https://www.apple.com/shop/product/MK0W2AM/A/)", not "Lightning to USB Camera Adapter."  


It would work with [USB-C Digital AV Multiport Adapter](https://www.apple.com/shop/product/MUF82AM/A/) for the USB-C type iPads.

A rotary encoder can be used to change the settings of giabalanaipico by long-pressing the push-button of the encorder, mute/unmute by clicking, and adjusting the system volume of your computer by rotating the encoder.


# How it looks & how it works
Check these short videos ([video1](https://github.com/3araht/giabalanai/blob/main/videos/giabalanai_keyboard.mp4), [video2](https://github.com/3araht/giabalanai/blob/main/videos/62buttons_38notes.mp4)) to see how it looks & how it works.  
Those are actually not giabalanaipico but giabalanai, but you'll get the picture.

Here's another [video](https://github.com/3araht/giabalanai/blob/main/videos/giabala_dangi_ep.16_theme_song_feat.Mr.Seto.mp4), trying to play (pardon my poor playing skills) a theme song of Giabala-Dangi (https://www.youtube.com/watch?v=WSVRJk6kDiM).

Check [my YouTube channel](https://www.youtube.com/channel/UC0zYtYMoxb0P7S8DPAkl0zA/) for more videos.

# Keyboard kit
## Lineup
There are total 6 types:

|Name               | Notes                                               |
|------------------|------------------------------------------------------|
| giabalanai       | 60 keys on the left-hand side for playing chords and 62 keys ＋ optional rotary encoder on the right-hand side for playing the melody (C-System)|
| giabaLEnai       | The right-hand side only version of giabalanai |
| giabaRInaix2     | Two pcs of the left-hand side of giabalanai. Rotary Encoder is not applicable. All 120 keys are isolated, so there is more flexibility for customizing the key layout (software modification is required). Bandoneon and Chromatone players might be interested in this model.|
| giabaRInai       | The left-hand side only version of giabalanai. For our friends who have giabaLEnai but want to have the left-hand side later on.|
| giabalanaipico   | Raspberry Pi Pico version of giabalanai. All keys on the right side keyboard are now independent. Register switches are now available. |
| giabaLEnaipico   |  The right-hand side only version of giabalanaipico |

The keyboard kits are available from [Yushakobo](https://yushakobo.jp/shop/consign_giabalanaipico/), or from [BOOTH](https://3araht.booth.pm/).  

Click [here](https://www.tenso.com/en/static/lp_shop_booth) for BOOTH overseas shipping!

All 6 models are available from [BOOTH](https://3araht.booth.pm/).

# Firmware

The giabalanaipico uses QMK for its firmware.
Please download codes from [here](https://github.com/3araht/giabalanaipico/blob/main/temp/qmk_firmware/keyboards/giabalanaipico) as a "beta" version.

Or, use this pre-compiled [uf2 file](https://github.com/3araht/giabalanaipico/blob/main/giabalanaipico_led_uf2.zip) for your convenience.

# Build Guide

[Japanese Build Guide](https://github.com/3araht/giabalanaipico/blob/main/docs/build.md)  
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
