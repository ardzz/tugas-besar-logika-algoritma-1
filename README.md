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

* Menghitung $\Sigma x_1$
$$\Sigma x_1 = 39 + 37 + 41 + 37 + 42 + 33 + 38 + 35 + 38 + 35 + 38 + 37 + 35 + 33 + 39 + 36 + 42 + 39 + 37 + 29 = 740$$
* Menghitung $\Sigma x_2$
$$\Sigma x_2 = 37 + 34 + 38 + 33 + 39 + 28 + 36 + 30 + 37 + 31 + 35 + 33 + 33 + 29 + 35 + 34 + 39 + 37 + 34 + 28 = 680$$
* Menghitung $\Sigma x_3$
$$\Sigma x_3 = 40 + 35 + 38 + 37 + 40 + 31 + 35 + 32 + 31 + 35 + 44 + 38 + 36 + 30 + 38 + 35 + 36 + 35 + 39 + 35 = 720$$
* Menghitung $\Sigma x_4$
$$\Sigma x_4 = 39 + 37 + 36 + 35 + 38 + 31 + 35 + 34 + 39 + 35 + 40 + 36 + 35 + 28 + 40 + 35 + 39 + 37 + 37 + 34 = 720$$
* Menghitung $\Sigma y$
$$\Sigma y = 41 + 40 + 43 + 41 + 42 + 36 + 42 + 39 + 40 + 38 + 48 + 43 + 42 + 36 + 44 + 43 + 45 + 44 + 41 + 36 = 820$$
* Menghitung $\Sigma x_1y$
$$\Sigma x_1y = 39 \times 41 + 37 \times 40 + 41 \times 43 + 37 \times 41 + 42 \times 42 + 33 \times 36 + 38 \times 42 + 35 \times 39 + 38 \times 40 + 35 \times 38 + 38 \times 48 + 37 \times 43 + 35 \times 42 + 33 \times 36 + 39 \times 44 + 36 \times 43 + 42 \times 45 + 39 \times 44 + 37 \times 41 + 29 \times 36 = 30474$$
* Menghitung $\Sigma x_2y$
$$\Sigma x_2y = 37 \times 41 + 34 \times 40 + 38 \times 43 + 33 \times 41 + 39 \times 42 + 28 \times 36 + 36 \times 42 + 30 \times 39 + 37 \times 40 + 31 \times 38 + 35 \times 48 + 33 \times 43 + 33 \times 42 + 29 \times 36 + 35 \times 44 + 34 \times 43 + 39 \times 45 + 37 \times 44 + 34 \times 41 + 28 \times 36 = 28026$$