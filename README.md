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