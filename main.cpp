#include <iostream>
#include <stdlib.h>
#include <time.h>

void fun_zap(int** m_1,int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			m_1[i][j] = rand() % 9 + 1;
		}
	}
}

void fun_print(int** m_1, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << m_1[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

int** fun_dobav(int** m_1, int n, int m) {
	int ** m_2 = (int**)realloc(m_1, (n + 1) * sizeof(int*));
	m_2[n] = (int*)calloc(m, sizeof(int));
	return m_2;
}

int ** fun_dobav_2(int ** m_1, int n, int m) {
	int ** m_2 = (int **)realloc(m_1, (n + 1) * sizeof(int*));
	m_2[n] = (int*)calloc(m, sizeof(int));
	for (int i = n; i >=1 ; i--) {
		for (int j = 0; j < m; j++) {
			m_2[i][j] = m_2[i - 1][j];
		}
	}
	for (int i = 0; i < m; i++) {
		m_2[0][i] = 0;
	}
	return m_2;
}

int ** fun_dobav_3(int** m_1, int n, int m, int id) {
	int ** m_2 = (int**)realloc(m_1, (n + 1) * sizeof(int*));
	m_2[n] = (int*)calloc(m, sizeof(int));
	for (int i = n; i >= id; i--) {
		for (int j = 0; j < m; j++) {
			m_2[i][j] = m_2[i - 1][j];
		}
	}
	for (int i = 0; i < m; i++) {
		m_2[id][i] = 0;
	}
	return m_2;
}

int ** fun_dell(int** m_1, int n, int m, int id) {
	for (int i = id; i < n-1; i++) {
		for (int j = 0; j < m; j++) {
			m_1[i][j] = m_1[i + 1][j];
		}
	}
	int** m_2 = (int**)realloc(m_1, (n - 1) * sizeof(int*));
	return m_2;
}

void fun_print_2(char** m_1, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < strlen(m_1[i]); j++) {
			std::cout << m_1[i][j] ;
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

int* fun_ob_abc(int** m_1, int** m_2, int** m_3, int n, int m, int* ms_1) {
	
	int temp = 0;
	int n_t = 0;
	int m_t = 0;
	int flag = 0;
	int id_1 = 0;
	int flag_2 = 1;
	do {
		
		temp = m_1[n_t][m_t];
		for (int i = 0; i < n; i++) {
			if (flag > 0) {
				break;
			}
			for (int j = 0; j < m; j++) {
				if (temp == m_2[i][j]) {
					ms_1[id_1] = temp;
					id_1++;
					flag++;
					break;
				}
			}
		}
		m_t++;
		flag = 0;
		if (m_t >= (m - 1)) {
			m_t = 0;
			n_t++;
		}
		if (n_t >= (n - 1)) {
			flag_2 = 0;
		}



	} while (flag_2 != 0);

	
	return ms_1;
}



int main() {
	srand(time(NULL));
	int flag_menu = 0;
	int n = 0;
	int m = 0;
	int id = 0;

	do {
		std::cout << "\n" << "Vvedite nomer zadani9 : " << "\n";
		std::cin >> flag_menu;


		if (flag_menu == 1) {
			std::cout << "\n" << "Zadanie nomer 1 : " << "\n";
			std::cout << "\n" << "Vvedite razmer massiva N= ";
			std::cin >> n;
			std::cout << "\n" << "Vvedite M= ";
			std::cin >> m;

			std::cout << "\n" << "Sozdanie massiva : " << "\n";
			int ** m_1 = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < n; i++) {
				m_1[i] = (int*)calloc(m, sizeof(int));
			}
			std::cout << "\n" << "Zapolnenie massiva :" << "\n";
			fun_zap(m_1, n, m);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_1, n, m);
			std::cout << "\n" << "Dobavlenie stroki : " << "\n";
			m_1=fun_dobav(m_1, n, m);
			n++;
			std::cout << "\n" << "Vuvod masiva: " << "\n";
			fun_print(m_1, n, m);
			std::cout << "\n" << "Dobavlenie stroki v nacalo : " << "\n";
			m_1=fun_dobav_2(m_1, n, m);
			n++;
			std::cout << "\n" << "Vivod masiva : " << "\n";
			fun_print(m_1, n, m);

			std::cout << "\n" << "Dobavlenie stoki v ykaz poziciu : " << "\n";
			std::cout << "\n" << "Ykahite posiciu : ";
			std::cin >> id;
			m_1 = fun_dobav_3(m_1, n, m, (id-1));
			n++;
			std::cout << "\n" << "Vivod masiva : " << "\n";
			fun_print(m_1, n, m);

			std::cout << "\n" << "dell stroki : " << "\n";
			std::cout << "\n" << "Ykahite posiciu : ";
			std::cin >> id;

			m_1=fun_dell(m_1, n, m, (id - 1));
			n--;
			std::cout << "\n" << "Vivod masiva : " << "\n";
			fun_print(m_1, n, m);

			for (int i = 0; i < n; i++) {
				free(m_1[i]);
			}
			free(m_1);




		}

		if (flag_menu == 2) {
			std::cout << "\n" << "Zadanie nomer 2 " << "\n";
			n = 5;
			m = 100;
			std::cout << "\n" << "Sozdanie massiva : " << "\n";
			char ** m_1 = (char**)calloc(n, sizeof(char*));
			for (int i = 0; i < n; i++) {
				m_1[i] = (char*)calloc(m, sizeof(char));
			}
			std::cout << "\n" << "Zapolnenie massiva :" << "\n";
			std::cout << "\n" << "Vvedite 5 familii : " << "\n";
			while (getchar() != '\n');
			for (int i = 0; i < n; i++) {
				
				gets_s(m_1[i], 100);
			}
			std::cout << "\n" << "Vivod masiva : " << "\n";
			fun_print_2(m_1, n, m);

			std::cout << "\n" << "Sortirovka massiva : " << "\n";
			char buffer[100] = { 0 };
			for (int q = 0; q < n; q++) {

				for (int i = 0; i < n-1; i++) {
					if (m_1[i][0] > m_1[i+1][0]) {
						for (int j = 0; j < m; j++) {
							buffer[j] = m_1[i][j];
							m_1[i][j] = m_1[i + 1][j];
							m_1[i + 1][j] = buffer[j];
						}
	
					}
				}
			}

			std::cout << "\n" << "Vivod masiva : " << "\n";
			fun_print_2(m_1, n, m);



			for (int i = 0; i < n; i++) {
				free(m_1[i]);
			}
			free(m_1);
			
		
		}


		if (flag_menu == 3) {
			std::cout << "\n" << "Zadanie nomer 1 : " << "\n";
			std::cout << "\n" << "Vvedite razmer massiva N= ";
			std::cin >> n;
			std::cout << "\n" << "Vvedite M= ";
			std::cin >> m;

			std::cout << "\n" << "Sozdanie massiva : " << "\n";
			int ** m_1 = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < n; i++) {
				m_1[i] = (int*)calloc(m, sizeof(int));
			}
			std::cout << "\n" << "Zapolnenie massiva :" << "\n";
			fun_zap(m_1, n, m);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_1, n, m);

			std::cout << "\n" << "Sozdanie massiva 2 : " << "\n";
			int ** m_2 = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < n; i++) {
				m_2[i] = (int*)calloc(m, sizeof(int));
			}
			std::cout << "\n" << "Zapolnenie massiva :" << "\n";
			fun_zap(m_2, n, m);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_2, n, m);

			std::cout << "\n" << "Sozdanie massiva 3: " << "\n";
			int ** m_3 = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < n; i++) {
				m_3[i] = (int*)calloc(m, sizeof(int));
			}
			std::cout << "\n" << "Zapolnenie massiva :" << "\n";
			fun_zap(m_3, n, m);
			std::cout << "\n" << "Vuvod masiva : " << "\n";
			fun_print(m_3, n, m);

			std::cout << "\n" << "Sozdanie odnomernogo massiva : " << "\n";
			
			int* ms_1 = (int*)calloc((n*m), sizeof(int));

			std::cout << "\n" << "Napolnenie massiva po obhie znac :" << "\n";

			ms_1 = fun_ob_abc(m_1, m_2, m_3, n, m, ms_1);

			std::cout << "\n" << "Vuvod masiva : " << "\n";

			for (int i = 0; i < (n*m) && ms_1[i]!=0; i++) {
				std::cout << ms_1[i] << " ";
			}
			






		}





	} while (flag_menu!=0);



}