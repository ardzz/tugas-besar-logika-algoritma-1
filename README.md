# Tugas Besar P. Logika dan Algoritma

<p align="center">
    <img src="https://github.com/ardzz/dasar-pemrogaman-2/raw/master/images/logo-polines.png" alt="Logo Polines" width="300" height="300">
</p>

### Memprediksi Presentase Kemanangan Pokemon Menggunakan Regresi Linear Berganda

### Landasan Teori

#### Apa itu Regresi Linear?

Regresi linear adalah teknik analisis data yang memprediksi nilai data yang tidak diketahui dengan menggunakan nilai data lain yang terkait dan diketahui. Secara matematis memodelkan variabel yang tidak diketahui atau tergantung dan variabel yang dikenal atau independen sebagai persamaan linier. Misalnya, anggaplah Anda memiliki data tentang pengeluaran dan pendapatan Anda untuk tahun lalu. Teknik regresi linier menganalisis data ini dan menentukan bahwa pengeluaran Anda adalah setengah dari penghasilan Anda. Mereka kemudian menghitung biaya masa depan yang tidak diketahui dengan mengurangi separuh pendapatan yang diketahui di masa depan.

#### Apa itu perbedaan Regresi Linear dan Regresi Linear Berganda?

Regresi linear berganda adalah regresi linier yang memiliki lebih dari satu variabel independen. Regresi linier berganda memiliki lebih dari satu variabel independen, sedangkan regresi linier hanya memiliki satu variabel independen.

#### Mengapa Regresi Linear Berganda?

Model regresi linier relatif sederhana dan memberikan rumus matematika yang mudah ditafsirkan untuk menghasilkan prediksi. Regresi linier adalah teknik statistik yang sudah ada dan mudah diterapkan pada perangkat lunak dan komputasi. Bisnis menggunakannya untuk mengonversi data mentah secara andal dan dapat diprediksi menjadi kecerdasan bisnis serta wawasan yang dapat ditindaklanjuti. Para ilmuwan di berbagai bidang, termasuk biologi serta ilmu perilaku, lingkungan, dan sosial menggunakan regresi linier untuk melakukan analisis data awal dan memprediksi tren masa depan. Banyak metode ilmu data, seperti machine learning dan kecerdasan buatan, menggunakan regresi linier untuk memecahkan masalah yang kompleks.

#### Apa itu regresi linier dalam machine learning?

Dalam machine learning, program komputer yang disebut algoritme menganalisis set data besar dan bekerja mundur dari data tersebut untuk menghitung persamaan regresi linier. Ilmuwan data melatih algoritme pada set data yang diketahui atau diberi label terlebih dahulu, kemudian menggunakan algoritme tersebut untuk memprediksi nilai yang tidak diketahui. Data dalam kehidupan nyata lebih rumit daripada contoh sebelumnya. Itu adalah alasan mengapa analisis regresi linier harus memodifikasi atau mengubah nilai data secara matematis untuk memenuhi empat asumsi berikut.

##### 1. Hubungan linier

Hubungan linier harus ada antara variabel independen dan dependen. Untuk menentukan hubungan ini, ilmuwan data membuat plot sebar—kumpulan acak nilai x dan y—untuk melihat apakah nilai tersebut berada di sepanjang garis lurus. Jika tidak, Anda dapat menerapkan fungsi nonlinier seperti akar kuadrat atau log untuk membuat hubungan linier antara dua variabel secara matematis.

##### 2. Independensi _(residual)_

Ilmuwan data menggunakan residual untuk mengukur akurasi prediksi. Residual adalah selisih antara data yang diamati dengan nilai prediksi. Residual tidak boleh memiliki pola yang dapat diidentifikasi. Misalnya, Anda tidak ingin residual tumbuh semakin besar seiring berjalannya waktu. Anda dapat menggunakan uji matematika yang berbeda, seperti uji Durbin-Watson, untuk menentukan independensi residual. Anda dapat menggunakan data dummy untuk mengganti variasi data apa pun, seperti data musiman.

##### 3. Normalitas

Teknik pembuatan grafik seperti plot Q-Q menentukan apakah residual terdistribusi secara normal. Residual harus berada di sepanjang garis diagonal di tengah grafik. Jika residual tidak dinormalisasi, Anda dapat menguji data untuk pencilan acak atau nilai yang tidak umum. Menghapus pencilan atau melakukan transformasi nonlinier dapat mengatasi masalah tersebut.

##### 4. Homoskedastisitas

Homoskedastisitas mengasumsikan bahwa residual memiliki varians atau standar deviasi yang konstan dari rata-rata untuk setiap nilai x. Jika tidak, hasil analisis mungkin tidak akurat. Jika asumsi ini tidak terpenuhi, Anda mungkin harus mengubah variabel dependen. Karena varians terjadi secara alami dalam set data yang besar, masuk akal untuk mengubah skala variabel dependen. Misalnya, alih-alih menggunakan ukuran populasi untuk memprediksi jumlah stasiun pemadam kebakaran di sebuah kota, ukuran populasi mungkin dapat digunakan untuk memprediksi jumlah stasiun pemadam kebakaran per orang.

#### Rumus Regresi Linear Berganda

Untuk memprediksi nilai y dari x, Anda dapat menggunakan rumus regresi linier berganda sebagai berikut:

$$
y = \beta_0 + \beta_1x_1 + \beta_2x_2 ... + \beta_nx_n

$$

Dimana $n$ adalah jumlah variabel independen, $x_1$ adalah variabel independen pertama, $x_2$ adalah variabel independen kedua, dan seterusnya. $\beta_0$ adalah intercept, $\beta_1$ adalah koefisien variabel independen pertama, $\beta_2$ adalah koefisien variabel independen kedua, dan seterusnya.

#### Contoh Regresi Linear Berganda

Diketahui sebuah data berikut ini:


| No | x1 | x2 | x3 | x4 | y  |
| -- | -- | -- | -- | -- | -- |
| 1  | 39 | 37 | 40 | 39 | 41 |
| 2  | 37 | 34 | 35 | 37 | 40 |
| 3  | 41 | 38 | 38 | 36 | 43 |
| 4  | 37 | 33 | 37 | 35 | 41 |
| 5  | 42 | 39 | 40 | 38 | 42 |
| 6  | 33 | 28 | 31 | 31 | 36 |
| 7  | 38 | 36 | 35 | 35 | 42 |
| 8  | 35 | 30 | 32 | 34 | 39 |
| 9  | 38 | 37 | 31 | 39 | 40 |
| 10 | 35 | 31 | 35 | 35 | 38 |
| 11 | 38 | 35 | 44 | 40 | 48 |
| 12 | 37 | 33 | 38 | 36 | 43 |
| 13 | 35 | 33 | 36 | 35 | 42 |
| 14 | 33 | 29 | 30 | 28 | 36 |
| 15 | 39 | 35 | 38 | 40 | 44 |
| 16 | 36 | 34 | 35 | 35 | 43 |
| 17 | 42 | 39 | 36 | 39 | 45 |
| 18 | 39 | 37 | 35 | 37 | 44 |
| 19 | 37 | 34 | 39 | 37 | 41 |
| 20 | 29 | 28 | 35 | 34 | 36 |

Langkah selanjutnya adalah mencari $\Sigma x_1$, $\Sigma x_2$, $\Sigma x_3$, $\Sigma x_4$, $\Sigma y$, $\Sigma x_1y$, $\Sigma x_2y$, $\Sigma x_3y$, $\Sigma x_4y$, $\Sigma x_1^2$, $\Sigma x_2^2$, $\Sigma x_3^2$, $\Sigma x_4^2$ $\Sigma x_1x_2$, $\Sigma x_1x_3$, $\Sigma x_1x_4$, $\Sigma x_2x_3$, $\Sigma x_2x_4$, $\Sigma x_3x_4$.

Contoh untuk mencari $\Sigma x_1$ adalah dengan menjumlahkan semua nilai x1, yaitu 39 + 37 + 41 + 37 + 42 + 33 + 38 + 35 + 38 + 35 + 38 + 37 + 35 + 33 + 39 + 36 + 42 + 39 + 37 + 29 = 720

$$
\Sigma x_1 = 740

$$

Dari data diatas dapat diperoleh:


| Variabel        | Nilai |
| --------------- | ----- |
| $\Sigma x_1$    | 740   |
| $\Sigma x_2$    | 680   |
| $\Sigma x_3$    | 720   |
| $\Sigma x_4$    | 720   |
| $\Sigma y$      | 820   |
| $\Sigma x_1y$   | 30474 |
| $\Sigma x_2y$   | 28026 |
| $\Sigma x_3y$   | 29633 |
| $\Sigma x_4y$   | 29635 |
| $\Sigma x_1^2$  | 27570 |
| $\Sigma x_2^2$  | 23344 |
| $\Sigma x_3^2$  | 26146 |
| $\Sigma x_4^2$  | 26088 |
| $\Sigma x_1x_2$ | 25354 |
| $\Sigma x_1x_3$ | 26743 |
| $\Sigma x_1x_4$ | 26764 |
| $\Sigma x_2x_3$ | 24592 |
| $\Sigma x_2x_4$ | 24627 |
| $\Sigma x_3x_4$ | 26051 |

Setelah itu kita akan mencari skor deviasi tiap variabel independen dan variabel dependen.

Contoh untuk mencari skor deviasi

$$
\Sigma x_n^2 = \Sigma x_n^2 - \frac{(\Sigma x_n)^2}{n}

$$

$$
\Sigma x_1^2 = 27570 - \frac{(740)^2}{20}

$$

$$
\Sigma x_1^2 = 27570 - 27380

$$

$$
\Sigma x_1^2 = 190

$$

Dari data diatas dapat diperoleh skor deviasi:


| Variabel        | Nilai |
| --------------- | ----- |
| $\Sigma x_1^2$  | 190   |
| $\Sigma x_2^2$  | 224   |
| $\Sigma x_3^2$  | 226   |
| $\Sigma x_4^2$  | 168   |
| $\Sigma y^2$    | 148   |
| $\Sigma x_1y$   | 134   |
| $\Sigma x_2y$   | 114   |
| $\Sigma x_3y$   | 146   |
| $\Sigma x_4y$   | 115   |
| $\Sigma x_1x_2$ | 194   |
| $\Sigma x_1x_3$ | 103   |
| $\Sigma x_1x_4$ | 124   |
| $\Sigma x_2x_3$ | 112   |
| $\Sigma x_2x_4$ | 147   |
| $\Sigma x_3x_4$ | 131   |

Maka persamaan regresi linier berganda untuk empat variabel independen adalah:

$$
y = \beta_0 + \beta_1x_1 + \beta_2x_2 + \beta_3x_3 + \beta_4x_4

$$

Untuk mencari koeffisien $\beta_0$, $\beta_1$, $\beta_2$, $\beta_3$, $\beta_4$ dapat digunakan persamaan Simultaneous Equation, sebagai berikut:

$$
\begin{aligned}
\Sigma x_1y &= \Sigma x_1 + \beta_1\Sigma x_1^2 + \beta_2\Sigma x_1x_2 + \beta_3\Sigma x_1x_3 + \beta_4\Sigma x_1x_4 \\
\Sigma x_2y &= \Sigma x_2 + \beta_1\Sigma x_1x_2 + \beta_2\Sigma x_2^2 + \beta_3\Sigma x_2x_3 + \beta_4\Sigma x_2x_4 \\
\Sigma x_3y &= \Sigma x_3 + \beta_1\Sigma x_1x_3 + \beta_2\Sigma x_2x_3 + \beta_3\Sigma x_3^2 + \beta_4\Sigma x_3x_4 \\
\Sigma x_4y &= \Sigma x_4 + \beta_1\Sigma x_1x_4 + \beta_2\Sigma x_2x_4 + \beta_3\Sigma x_3x_4 + \beta_4\Sigma x_4^2
\end{aligned}

$$

Dengan menggunakan persamaan Simultaneous Equation diatas, maka dapat diperoleh:

$$
\begin{aligned}
134 = \beta_1(190) + \beta_2(194) + \beta_3(103) + \beta_4(124) \\
146 = \beta_1(194) + \beta_2(224) + \beta_3(112) + \beta_4(147) \\
113 = \beta_1(103) + \beta_2(112) + \beta_3(226) + \beta_4(131) \\
115 = \beta_1(124) + \beta_2(147) + \beta_3(131) + \beta_4(168)
\end{aligned}

$$

Setelah itu kita akan mencari nilai $\beta_0$, $\beta_1$, $\beta_2$, $\beta_3$, $\beta_4$ dengan menggunakan metode Gauss Elimination.

$$
\begin{aligned}
\begin{bmatrix}
190 & 194 & 103 & 124 &| 134 \\
194 & 224 & 112 & 147 &| 146 \\
103 & 112 & 226 & 131 &| 113 \\
124 & 147 & 131 & 168 &| 115
\end{bmatrix}
\end{aligned}

$$

Dengan bantuan [kalkulator online](https://onlinemschool.com/math/assistance/equation/gaus/), maka dapat diperoleh:

$$
\begin{aligned}
\beta_1 = \frac{13332075}{42090757} = 0.316 \\
\beta_2 = \frac{8277471}{42090757} = 0.197 \\
\beta_3 = \frac{7424042}{42090757} = 0.176 \\
\beta_4 = \frac{5940012}{42090757} = 0.141
\end{aligned}

$$

Dengan demikian persamaan regresi linier berganda untuk empat variabel independen adalah:

$$
y = 0.316x_1 + 0.197x_2 + 0.176x_3 + 0.141x_4

$$

#### Pengaplikasian Regresi Linier Berganda pada Bahasa Pemrograman C

Sebelum membuat program untuk menghitung regresi linear berganda, dibutuhkan alat dan library yang akan digunakan. Berikut adalah alat dan library yang digunakan:

Alat yang digunakan:

* [GNU GCC Compiler](https://gcc.gnu.org/)
* [Ninja](https://ninja-build.org/)
* [Cmake](https://cmake.org/)
* [Clion](https://www.jetbrains.com/clion/)

Library yang digunakan:

* [csvReader.h](https://github.com/SongDanielLi/cCsvReader)
* [math.h](https://www.gnu.org/software/libc/manual/html_node/Mathematics.html)
* [stdio.h](https://www.gnu.org/software/libc/manual/html_node/Standard-IO.html)

#### Preparasi Data

1. Memuat data dari file csv

```c
CSVFILE file;
char *dataset = "/Users/macbookair/Collage/Logika dan Algoritma/Regresi Linear Berganda/dataset.csv";
long double x1[N], x2[N], x3[N], x4[N], x5[N], x6[N], y[N];
long double y_hat;
int index = 0;

if(csvOpen(&file, dataset)) {
    while(csvReadLine(&file)){
        x1[index] = file.GetField(&file, "Attack");
        x2[index] = file.GetField(&file, "Defense");
        x3[index] = file.GetField(&file, "Sp. Atk");
        x4[index] = file.GetField(&file, "Sp. Def");
        x5[index] = file.GetField(&file, "Speed");
        x6[index] = file.GetField(&file, "HP");
        y[index] = file.GetField(&file, "Win Percentage");
        printf("[%d] %Lf %Lf %Lf %Lf %Lf %Lf %Lf\n", index, x1[index], x2[index], x3[index], x4[index], x5[index], x6[index], y[index]);
        index++;
    }
}
```
