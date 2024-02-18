#include "dialog.h"
#include "ui_dialog.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
#include <fstream>
#include <iostream>
#include <vector>
//#include <ifstream>
#include <algorithm>
#include <iterator>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<long long> list_sinapsov(10105);// = {};
std::vector<unsigned long long> list_neyronov(202);// = {};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
  ui->setupUi(this);
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////// (1) //// Считывание из файла нейронов в
  ///массив:
  ///////////////////////////////////////////////////////////////////////////////////////////////
  try {
    std::fstream input(
        //  "/home/viktor/my_projects_qt_2/tsikl_otlicheniya_edinitsi_s_massivami_2/neyroni.list"
        "/home/viktor/my_projects_qt_2/Funkciya_podachi_signalov_na_vhod/"
        "neyroni_i_signal.txt");
    if (!input) {
      std::cerr << "ERROR: Cannot open "
                   "'/home/viktor/my_projects_qt_2/"
                   "Funkciya_podachi_signalov_na_vhod/neyroni_i_signal.txt'!"
                << std::endl;
      //  exit(1);
    }
    std::copy(std::istream_iterator<int>(input), std::istream_iterator<int>(),
              std::back_inserter(list_neyronov));
    //   std::cout << list_neyronov[3] << std::endl;

  } catch (const std::exception &ex) {
    std::cerr << "Exception: '" << ex.what() << "'!" << std::endl;
    //  exit(1);
  }
  //////////////////////////////// (1) ///// Конец считывания из файла нейронов
  ///в массив. ////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////// (2) //// Считывание из файла синапсов в
  ///массив:
  ///////////////////////////////////////////////////////////////////////
  try {
    std::fstream input(
        //  "/home/viktor/my_projects_qt_2/tsikl_otlicheniya_edinitsi_s_massivami_2/sinapsi.list"
          
//        "/home/viktor/my_projects_qt_2/"
//        "build-zapolnenie_sinapsov_sluchajnymi_nachalnymi_soprotivleniyami_2-"
//        "Desktop_Qt_5_12_12_GCC_64bit-Debug/sinapsi.txt"
          
          "/home/viktor/my_projects_qt_2/zapolnenie_0/0_sinapsi.txt"
          
          
          );
      
    
    
    if (!input) {
      std::cerr << "ERROR: Cannot open "
                   "'/home/viktor/my_projects_qt_2/"
                   "build-zapolnenie_sinapsov_sluchajnymi_nachalnymi_"
                   "soprotivleniyami_2-Desktop_Qt_5_12_12_GCC_64bit-Debug/"
                   "sinapsi.txt'!"
                << std::endl;
      //  exit(1);
    }
    std::copy(std::istream_iterator<int>(input), std::istream_iterator<int>(),
              std::back_inserter(list_sinapsov));
    //    std::cout << list_sinapsov[3] << std::endl;

  } catch (const std::exception &ex) {
    std::cerr << "Exception: '" << ex.what() << "'!" << std::endl;
    //  exit(1);
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////// (3) Функция решения
  ///funktsiya_resheniya
  //////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //    for (int var = 101; var < 201; ++var) // это диапазон нейронов
  //    {
  //        // это для одного 101 нейрона:
  //        for (int index_neyrona=1,index_sinapsa = 1;index_neyrona < 201,
  //        index_sinapsa<10101 ;
  //        ++index_neyrona,index_sinapsa=index_sinapsa+100)
  //        // где то тут ошибка за диапазон выходит
  //        {
  //            // тут можно костыль поставить проверка что
  //            Synaps::Peremennaia_Soprotivlenie_Sinapsa[index_sinapsa] не 0 if
  //            (Synaps::Peremennaia_Soprotivlenie_Sinapsa[index_sinapsa]==0)
  //            {
  //                Synaps::Peremennaia_Soprotivlenie_Sinapsa[index_sinapsa]=1;
  //            }
  //            Neiron::Peremennaia_Zariad_Neirona[var]=Neiron::Peremennaia_Zariad_Neirona[var]+
  //                            (Neiron::Peremennaia_Zariad_Neirona[index_neyrona]/
  //                            Synaps::Peremennaia_Soprotivlenie_Sinapsa[index_sinapsa]);
  //            // вот здесь генерируется исключение деление на 0
  //        }

  //    }
  // нейроны второго ряда посчитаны
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  for (int var = 101; var < 201; ++var) // это диапазон нейронов
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
      list_neyronov[var] = list_neyronov[var] + (list_neyronov[index_neyrona] /
                                                 list_sinapsov[index_sinapsa]);
    }
  }
  // нейроны второго ряда посчитаны
  // тут надо досчитать поледний 201 нейрон.
  for (int index_neyrona = 101, index_sinapsa = 10001; index_neyrona < 201;
       ++index_neyrona, ++index_sinapsa)
  {
      if (list_sinapsov[index_sinapsa] == 0) { // для избежания деления на 0
          list_sinapsov[index_sinapsa] = 1;
      }
      
    list_neyronov[201] = list_neyronov[201] + (list_neyronov[index_neyrona] /
                                               list_sinapsov[index_sinapsa]);//  list_sinapsov[index_sinapsa]==0
  }
  /// проверяем ошибку:
  //      if (file.readLine().simplified().toULongLong (&ok, 10)<1073741824) {
  //      // меньше половины возможной генерации random
  //          // программа считает это не 1
  //          ui->label->setText("программа считает это не 1");
  //      }
  //      else {
  //          ui->label->setText("программа считает это 1");
  //      }
  if (list_neyronov[201] < 
      1073741824) { // меньше половины возможной генерации random
    // программа считает это не 1
    // тут надо показать что решила программа
    ui->label->setText("программа считает это не 1"); 
  } else {
    // программа считает это 1
    // тут надо показать что решила программа
    ui->label->setText("программа считает это 1");
  }
  // вычисляем размер ошибки
 long long oshibka =   1073741824-list_neyronov[201] ; /// получается если oshibka
  //   больше 0 то ошибка, если 0 или меньше то нет ошибки
 // заведомо ошибка, выведем 201 нейрон
  std::cout << "201 нейрон = "  << list_neyronov[201] << std::endl;
  std::cout << "ошибка = "  << oshibka << std::endl;
  // TODO: надо сделать функцию решения как раньше в классе нейронная сеть: вызываем когда надо... Или можно пока goto
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /// 
  ///  далее кнопка "Неправильно" запускает процесс подстройки сопротивлений синапсов
  ///  а может без кнопки если заведомо известно что есть ошибка
  /// /// Уменьшаем ... синапс на 1 и пересчитываем ошибку в смысле сначала снова функция решения а потом считаем ошибку.
  ///  Видима нужна какая-то глобальная переменная хранящая текущий синапс... int tekuschiy_sinaps... Начинаем видимо с 0
  ///  int tekuschiy_sinaps=0; на закрытие программы неплохо её в файл писать. А как насчёт действия - вычитать по 1 из синапсов или прибавлять?
  /// Вроде вычитать. Значит берём синапс с индексом 0 и вычитаем из него 1
  /// list_sinapsov[0]=list_sinapsov[0]-1;
  /// Может проверить крайнее положение когда все синапсы по нулям?
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /// 
  /// 
  /// 
  ///  
} // Dialog::Dialog(QWidget *parent)

Dialog::~Dialog() { delete ui; }
