Word Frequency Counter adalah app yang menghitung frequensi dari setiap kata 
pada sebuah file. 

Contoh Penggunaan:

```bash
./word-frequency-counter ./file.txt
```

Cara Kerja: 
1. Buka file dan simpan dalam `ifstream`
2. Buat loop untuk untuk setiap word pada `ifstream`
3. Tambahkan setiap kata dan simpan pada hash map