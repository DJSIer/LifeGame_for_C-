#ライフワークゲームをC++で実装編

サークル用のC++入門

ライフゲーム

ライフゲームとは生命の誕生や死を計算機上でシミュレーションするゲームです。点が生命を表し、 生命は過疎や過密によって死にます。また適当な条件で繁殖します。 ゲームとはいっても目的などはなく、ただ眺めるのが基本です。 いろいろな形ではじめてみると、ちょっと想像できないような変化が楽しめます。

ルール

世界は碁盤の目状のマスで構成されます。 各マスは生命がいる、いないで黒と白に色分けされます。 次の世代には以下のルールで生命が誕生します。

1.生命のいないところには周囲にちょうど３個の生命がある場合に新しく生命が誕生します。

2.生命がいるところは、周囲に２個、または３個の生命がいる場合に、そのまま生命が残ります。 そうでない場合には死んでしまいます。

ルールを変えてみたり、２種類以上の性質の異なる生命を考えてみたりすれば、 より複雑な生態系をシミュレートすることもできます。

##エスケープシーケンス 
https://www.grapecity.com/developer/support/powernews/column/clang/047/page02.htm
