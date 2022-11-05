#include<iostream>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <sstream>
#include <iomanip>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include "device_launch_parameters.h"
#include "GpuSolver.h"
#include "filters_CPU.cpp"
#include <chrono>
using namespace std::chrono;
//Load Images
#define STB_IMAGE_IMPLEMENTATION
// Write Images
#define STB_IMAGE_WRITE_IMPLEMENTATION

//#define STBIR_INCLUDE_STB_IMAGE_RESIZE_H

#include "include/stb_image.h"
//#include "include/stb_image_resize.h"
#include "include/stb_image_write.h"

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	/// <summary>
	/// Sumário para MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ load;
	protected:


	private: System::Windows::Forms::Button^ exit;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ close;
	private: System::Windows::Forms::Label^ time_exec;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ convertToGray;
	private: System::Windows::Forms::Button^ b_teste;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	protected:

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->load = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->close = (gcnew System::Windows::Forms::Button());
			this->time_exec = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->convertToGray = (gcnew System::Windows::Forms::Button());
			this->b_teste = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// load
			// 
			this->load->Location = System::Drawing::Point(22, 7);
			this->load->Margin = System::Windows::Forms::Padding(2);
			this->load->Name = L"load";
			this->load->Size = System::Drawing::Size(117, 44);
			this->load->TabIndex = 0;
			this->load->Text = L"Carregar Imagem";
			this->load->UseVisualStyleBackColor = true;
			this->load->Click += gcnew System::EventHandler(this, &MyForm::load_Click);
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->exit->Cursor = System::Windows::Forms::Cursors::No;
			this->exit->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->exit->Location = System::Drawing::Point(1157, 10);
			this->exit->Margin = System::Windows::Forms::Padding(2);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(113, 38);
			this->exit->TabIndex = 2;
			this->exit->Text = L"Finalizar APP";
			this->exit->UseVisualStyleBackColor = false;
			this->exit->Click += gcnew System::EventHandler(this, &MyForm::exit_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(5, 116);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(630, 600);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(646, 116);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(630, 600);
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// close
			// 
			this->close->Location = System::Drawing::Point(143, 7);
			this->close->Margin = System::Windows::Forms::Padding(2);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(106, 44);
			this->close->TabIndex = 5;
			this->close->Text = L"Fechar Imagem";
			this->close->UseVisualStyleBackColor = true;
			this->close->Click += gcnew System::EventHandler(this, &MyForm::close_Click);
			// 
			// time_exec
			// 
			this->time_exec->AutoSize = true;
			this->time_exec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time_exec->Location = System::Drawing::Point(885, 82);
			this->time_exec->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->time_exec->Name = L"time_exec";
			this->time_exec->Size = System::Drawing::Size(202, 20);
			this->time_exec->TabIndex = 6;
			this->time_exec->Text = L"Tempo de processamento: ";
			this->time_exec->Click += gcnew System::EventHandler(this, &MyForm::time_exec_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(889, 59);
			this->checkBox1->Margin = System::Windows::Forms::Padding(2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(291, 17);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"Ativar Processamento Paralelo (Unidade Gráfica - GPU) ";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// convertToGray
			// 
			this->convertToGray->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->convertToGray->Location = System::Drawing::Point(193, 59);
			this->convertToGray->Margin = System::Windows::Forms::Padding(2);
			this->convertToGray->Name = L"convertToGray";
			this->convertToGray->Size = System::Drawing::Size(147, 44);
			this->convertToGray->TabIndex = 8;
			this->convertToGray->Text = L"RGB para Escala de Cinza";
			this->convertToGray->UseVisualStyleBackColor = false;
			this->convertToGray->Click += gcnew System::EventHandler(this, &MyForm::convertToGray_Click);
			// 
			// b_teste
			// 
			this->b_teste->ForeColor = System::Drawing::Color::Crimson;
			this->b_teste->Location = System::Drawing::Point(371, 59);
			this->b_teste->Margin = System::Windows::Forms::Padding(2);
			this->b_teste->Name = L"b_teste";
			this->b_teste->Size = System::Drawing::Size(88, 44);
			this->b_teste->TabIndex = 9;
			this->b_teste->Text = L"Filtro Vermelho";
			this->b_teste->UseVisualStyleBackColor = true;
			this->b_teste->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button1
			// 
			this->button1->ForeColor = System::Drawing::Color::Green;
			this->button1->Location = System::Drawing::Point(463, 59);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 44);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Filtro Verde";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// button2
			// 
			this->button2->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->button2->Location = System::Drawing::Point(551, 58);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(84, 44);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Filtro Azul";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button3->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->button3->Location = System::Drawing::Point(662, 58);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(84, 44);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Inverter cores";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1280, 734);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->b_teste);
			this->Controls->Add(this->convertToGray);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->time_exec);
			this->Controls->Add(this->close);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->load);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PP_Image_Recolor";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void load_Click(System::Object^ sender, System::EventArgs^ e) {

		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		//insert here the filter if you want
		//ofd->Filter..
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			//img_input->Image = Image::FromFile(ofd->FileName);
			//System::String^ strFilename = ofd->FileName;

			pictureBox1->ImageLocation = ofd->FileName;

		}
		/*useGPU obj;
		int c[5] = {};
		int a[5] = { 0, 1, 2, 3, 4 };
		int b[5] = { 10, 11, 12, 13, 14 };

		obj.adding(c, a, b, 5);
		textBox1->Text = System::Convert::ToString(c[0]);*/
	}
	private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void close_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->ImageLocation = "";
		pictureBox2->Image = nullptr;
	}
private: System::Void convertToGray_Click(System::Object^ sender, System::EventArgs^ e) {
	useGPU obj;
	System::String^ file = pictureBox1->ImageLocation;
	std::string converted_xyz = msclr::interop::marshal_as< std::string >(file);
	int width, height, channels;
	const char* c = converted_xyz.c_str();
	unsigned char* img = stbi_load(c, &width, &height, &channels, 4);
	int time = 0;

	if (checkBox1->Checked) {
		time=obj.ImageToGrayGpu(img, width, height);
	}
	else {
		auto start = high_resolution_clock::now();
		ConvertImageToGrayCpu(img, width, height);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		time = duration.count();
	}

	time_exec->Text = "Tempo de Processamento: "+ time.ToString() + " µs";
	stbi_write_png("images/output.jpg", width, height, 4, img, 4 * width);
	pictureBox2->ImageLocation = "images/output.jpg";
	stbi_image_free(img);
}


private: System::Void time_exec_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			   useGPU obj;
		   System::String^ file = pictureBox1->ImageLocation;
		   std::string converted_xyz = msclr::interop::marshal_as< std::string >(file);
		   int width, height, channels;
		   const char* c = converted_xyz.c_str();
		   unsigned char* img = stbi_load(c, &width, &height, &channels, 4);
		   int time = 0;

		   if (checkBox1->Checked) {
			   time = obj.ImageToRedGpu(img, width, height);
		   }
		   else {
			   auto start = high_resolution_clock::now();
			   ConvertImageToRed(img, width, height);
			   auto stop = high_resolution_clock::now();
			   auto duration = duration_cast<microseconds>(stop - start);
			   time = duration.count();
		   }

		   time_exec->Text = "Tempo de Processamento: " + time.ToString() + " µs";
		   stbi_write_png("images/output.jpg", width, height, 4, img, 4 * width);
		   pictureBox2->ImageLocation = "images/output.jpg";
		   stbi_image_free(img);
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	useGPU obj;
	System::String^ file = pictureBox1->ImageLocation;
	std::string converted_xyz = msclr::interop::marshal_as< std::string >(file);
	int width, height, channels;
	const char* c = converted_xyz.c_str();
	unsigned char* img = stbi_load(c, &width, &height, &channels, 4);
	int time = 0;

	if (checkBox1->Checked) {
		time = obj.ImageToGreenGpu(img, width, height);
	}
	else {
		auto start = high_resolution_clock::now();
		ConvertImageToGreen(img, width, height);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		time = duration.count();
	}

	time_exec->Text = "Tempo de Processamento: " + time.ToString() + " µs";
	stbi_write_png("images/output.jpg", width, height, 4, img, 4 * width);
	pictureBox2->ImageLocation = "images/output.jpg";
	stbi_image_free(img);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	useGPU obj;
	System::String^ file = pictureBox1->ImageLocation;
	std::string converted_xyz = msclr::interop::marshal_as< std::string >(file);
	int width, height, channels;
	const char* c = converted_xyz.c_str();
	unsigned char* img = stbi_load(c, &width, &height, &channels, 4);
	int time = 0;

	if (checkBox1->Checked) {
		time = obj.ImageToBlueGpu(img, width, height);
	}
	else {
		auto start = high_resolution_clock::now();
		ConvertImageToBlue(img, width, height);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		time = duration.count();
	}

	time_exec->Text = "Tempo de Processamento: " + time.ToString() + " µs";
	stbi_write_png("images/output.jpg", width, height, 4, img, 4 * width);
	pictureBox2->ImageLocation = "images/output.jpg";
	stbi_image_free(img);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	useGPU obj;
	System::String^ file = pictureBox1->ImageLocation;
	std::string converted_xyz = msclr::interop::marshal_as< std::string >(file);
	int width, height, channels;
	const char* c = converted_xyz.c_str();
	unsigned char* img = stbi_load(c, &width, &height, &channels, 4);
	int time = 0;

	if (checkBox1->Checked) {
		time = obj.ImageToInvGpu(img, width, height);
	}
	else {
		auto start = high_resolution_clock::now();
		ConvertImageInv(img, width, height);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		time = duration.count();
	}

	time_exec->Text = "Tempo de Processamento: " + time.ToString() + " µs";
	stbi_write_png("images/output.jpg", width, height, 4, img, 4 * width);
	pictureBox2->ImageLocation = "images/output.jpg";
	stbi_image_free(img);
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
