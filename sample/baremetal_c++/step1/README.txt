v850 gcc コンパイラ＆ athrill でC++のクラスが使えるかどうか調査メモ書き．

■わかったこと
　・g++のコンパイラを用意しないといけない．
　　⇒gccとbinutilsをc++付きでビルドすることで解決した．まだ未公開．
　・athrillがC++用のデバッグ情報を参照すると落ちる問題が発生
　　⇒暫定対処で落ちないようにした．ただ，C++クラスオブジェクトはデバッグできないので要注意．
　　　⇒TODO：athrillのC++ dwarf対応をしたくなった．
　・クラスオブジェクトをグローバル変数定義した場合，コンストラクタが呼び出されない問題が発生
　　⇒自前で特定領域を見て，初期化対象コンストラクタを呼ばないといけないらしいが，
　　　どの領域をどうやって参照するのかがわからなかったので，一旦，お手上げ状態．
　　　⇒ローカル変数として定義した場合は正しく動作したので，上記は制限にしておく．
　・動的メモリ確保するC++操作はできない．
　　⇒new, delete, string, vector...