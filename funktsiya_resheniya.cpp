  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
for (int var = 101; var < 201; ++var) // это диапазон нейронов // NOTE: функция решения
{
    //        // это для одного 101 нейрона:
    for (int index_neyrona = 1, index_sinapsa = 1;
         index_neyrona < 201, index_sinapsa < 10101;
         ++index_neyrona, index_sinapsa = index_sinapsa + 100)
    // выход за индекс?
    {
        //            // тут можно костыль поставить проверка что
        //            Synaps::Peremennaia_Soprotivlenie_Sinapsa[index_sinapsa] не
        //            0
        if (list_sinapsov[index_sinapsa] == 0) { // для избежания деления на 0
            list_sinapsov[index_sinapsa] = 1;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////      
        //      list_neyronov[var] = list_neyronov[var] + (list_neyronov[index_neyrona] / list_sinapsov[index_sinapsa]);
        //      std::cout << list_neyronov[var] <<" = "<< list_neyronov[var] <<" + " << (list_neyronov[index_neyrona] / list_sinapsov[index_sinapsa])<<"\n";
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////      
        //  ui->textEdit->append (QString::number(list_neyronov[index_neyrona]));
        // тут надо вывести что получается
        //  std::cout << list_neyronov[index_neyrona] <<"("<< index_neyrona << ")"<< std::endl;
        //  std::cout << list_neyronov[var] <<"("<< var << ")"<< std::endl;
        // std::cout << list_sinapsov[index_sinapsa] <<"("<< index_sinapsa << ")"<< std::endl;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////      
        
    }
    // ui->textEdit->append (QString::number(list_neyronov[var]));
    //  std::cout << list_neyronov[var] <<"("<< var << ")"<< std::endl;
    //   std::cout << list_neyronov[index_neyrona] <<"("<< index_neyrona << ")"<< std::endl;
}
// нейроны второго ряда посчитаны
// тут надо досчитать последний 201 нейрон.
for (int index_neyrona = 101, index_sinapsa = 10001; index_neyrona < 201;
     ++index_neyrona, ++index_sinapsa)
{
    if (list_sinapsov[index_sinapsa] == 0) { // для избежания деления на 0
        list_sinapsov[index_sinapsa] = 1;
    }
    
    list_neyronov[201] = list_neyronov[201] + (list_neyronov[index_neyrona] /
                                               list_sinapsov[index_sinapsa]);//  list_sinapsov[index_sinapsa]==0
}
//   ui->textEdit->append (QString::number(list_neyronov[201]));
/// проверяем ошибку:
//      if (file.readLine().simplified().toULongLong (&ok, 10)<1073741824) {
//      // меньше половины возможной генерации random
//          // программа считает это не 1
//          ui->label->setText("программа считает это не 1");
//      }
//      else {
//          ui->label->setText("программа считает это 1");
//      }
//  if (list_neyronov[201] < 
//      1073741824) { // меньше половины возможной генерации random
//    // программа считает это не 1
//    // тут надо показать что решила программа
//    ui->label->setText("программа считает это не 1"); 
//  } else {
//    // программа считает это 1
//    // тут надо показать что решила программа
//    ui->label->setText("программа считает это 1");
//  }
// вычисляем размер ошибки
long long oshibka =   1073741824-list_neyronov[201] ; /// получается если oshibka
    //   больше 0 то ошибка, если 0 или меньше то нет ошибки
// заведомо ошибка, выведем 201 нейрон
//  std::cout << "201 нейрон = "  << list_neyronov[201] << std::endl;
//  std::cout << "ошибка = "  << oshibka << std::endl;
// TODO: надо сделать функцию решения как раньше в классе нейронная сеть: вызываем когда надо... Или можно пока goto
