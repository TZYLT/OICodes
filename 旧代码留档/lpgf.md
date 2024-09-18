
# 简单的问题

> 已知两个随机变量 $X,Y$ 分别独立的等概率均匀出现在 $[0,1]$ 中。  
> 问：$X+Y\le 1$ 的概率是？

这是一个显然的问题，小学生都会口算，但是我们姑且认为我们不知道答案。

有一种好东西叫做**概率型生成函数**，这里给出它的基本形式
$$f(x)=\sum_{i=0}P(X=i)x^i$$

我们非常想依靠概率型生成函数来计算我们的概率问题。
  
很可惜，上面的式子所表示的变量是离散的，而我们的变量却是连续的。

推广！如果它不是连续的，我们就尝试着让它趋于连续。我们考虑项不是整数的情况：
$$F(x)=\sum_{i=0}^nP\left(X\in \left[\frac{i}{n},\frac{i+1}{n}\right]\right)x^{\frac{i}{n}}$$

设我们把区间分成长度相等的 $n$ 段，当 $n$ 趋于正无穷时，整个区间被完全细分，每一项的意义都为区间中的一个值。显然的每一段的概率 $P\left(X\in \left[\frac{i}{n},\frac{i+1}{n}\right]\right)$ 都等于 $\frac{1}{n}$，我们将此式化简:
$$F(x)=\lim_{n \to \infty} \sum_{i=0}^n\frac{1}{n}x^{\frac{i}{n}}$$

**由于我还没有找到此式封闭形式，姑且使用暴力求和。**

此时我们就写出了 $X$ 的概率型生成函数，$Y$ 同理。

于是取 $X,Y$ 的操作的生成函数即为:
$$
\begin{align}
G(x)&=&F(x)*F(x)\\
\end{align}
$$
我们做简单化简
$$
\begin{align}
&=\sum_{i=0}^n\frac{1}{n}x^{\frac{i}{n}}\sum_{j=0}^n\frac{1}{n}x^{\frac{j}{n}}\\
&=\sum_{i=0}^n\sum_{j=0}^n\frac{1}{n}x^{\frac{i}{n}}\frac{1}{n}x^{\frac{j}{n}}\\
&=\sum_{i=0}^n\sum_{j=0}^n\frac{1}{n^2}x^{\frac{i+j}{n}}\\
&=\sum_{i=0}^{2n}\sum_{j=0}^{\min(i,n)}\frac{1}{n^2}x^{\frac{i}{n}}\\
\end{align}
$$
最后我们裂项化简
$$
\begin{align}
&=\sum_{i=0}^{n}\sum_{j=0}^{\min(i,n)}\frac{1}{n^2}x^{\frac{i}{n}}+\sum_{i=n+1}^{2n}\sum_{j=0}^{n}\frac{1}{n^2}x^{\frac{i}{n}}\\
&=\sum_{i=0}^{n}\frac{i}{n^2}x^{\frac{i}{n}}+\sum_{i=n+1}^{2n}\frac{1}{n}x^{\frac{i}{n}}\\
\end{align}
$$
非常好，目前的被项已经完全化简。
由于 $X+Y\le1$ 我们取指数 $i\in[0,1]$ 的项：
$$G(x)=\sum_{i=0}^{n}\frac{i}{n^2}x^{\frac{i}{n}}$$
现在我们离答案只剩下最后一步，对系数求和。
$$
\begin{align}
ans&=\sum_{i=0}^{n}\frac{i}{n^2}\\
&=\frac{1}{n^2}\sum_{i=0}^{n}i\\
&=\frac{1}{n^2}\frac{n(n+1)}{2}\\
&=\frac{n^2+n}{2n^2}\\
&=\frac{1}{2}+\frac{1}{2n}\\
\end{align}$$
根据我们前面的定义，$n$ 需要趋于正无穷，即答案为 $\frac{1}{2}$，结果显然正确。

后记：我们在这里使用了巨大的篇幅才解决了一道如此简单的题，但以上的求解过程具有一定的启发意义。倘若我们能够找到 $F(x)$ 的封闭形式，就能够进行更加复杂而庞大的计算，并与传统的生成函数构建起桥梁。


---
$\texttt{by TZYLT 2024.07.27}$