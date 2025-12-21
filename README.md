# arduino_test (CH32V)

このプロジェクトは CH32V03 系で動作する Flash EEPROM エミュレーションのサンプルです。

## 変更点（CH32V Arduino フレームワーク向け）
- `SAMPLE_CODE` のデフォルトを `0` に変更しました（`src/flash_eep.h`）。これにより、従来の `main()` を持つサンプルはビルドに含まれず、Arduino フレームワークの `main()` と競合しません。
- Arduino 用のテストを追加しました：`src/flash_test_arduino.cpp`（`setup()` / `loop()` を実装）。USBシリアル（Serial, 115200）で動作確認できます。
- ハードウェア固有のヘッダは公開ヘッダ（`flash_eep.h`）から除き、実装ファイル（`flash_eep.cpp`）内で扱うように修正しました（Arduino コアとの定義の重複を回避）。

## ビルド方法
PlatformIO を使用します。

```bash
pio run
```

## 実行 / テスト
- ボードに書き込み後、シリアルモニタで 115200 ボーを開いてください。
- `src/flash_test_arduino.cpp` が初期化・簡単な write/read テストを行い、結果をシリアルに出力します。

## 開発上の注意
- 元のサンプル（`src/flash_test.cpp`）をビルドに再び含める場合は、`src/flash_eep.h` 内の `SAMPLE_CODE` を `1` に変更してください。ただしその場合、Arduino フレームワークの `main()` と競合するため、Arduino モードではビルドが失敗する点に注意してください。

---
（自動修正済み：ビルドが CH32V Arduino フレームワークで通るように調整済み）
