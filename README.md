# TESTES GLOBO
O repositorio tem uma pasta por cada ponto da prova de C. Dentro dessas pastas, tem as siguintes:

  SRC: - Contem:
                Arquivo codigo fonte em C, com formato: test_nro.c (onde nro é o nro do ponto da prova de C),
                Arquivo exe (porque já foi compilado e gerado o arquivo), com formato: teste_nro.exe,
                Arquivo shell script, para testes, com formato teste_ex_nro.sh.
                
  OUTPUT - Contem:
                  Arquivo de resultado de teste, com prints.
  
Começando

Pré-requisitos
        
        i) Para compilar precisa ter instalado um compilador gcc, no Windows 11, pode ser msys64,
        ii) Visual Studio Code,
        iii) GitBash,
        iv) Instalar o WSL ou o Windows Subsystem para Linux (para execução dos shell scripts)
                
Instalação
        i) Download dos arquivos da pasta SRC,
        ii) Ingresse na pasta onde fiz download dos arquivos, click com botão direito, "GitBash Here"
           ![image](https://user-images.githubusercontent.com/131888548/234986535-86f8da11-79cd-468f-b5cc-4ea03e4d71d9.png)

        iii) Escrever e executar o comando: gcc teste_nro.c -o teste_nro
        
            ![image](https://user-images.githubusercontent.com/131888548/234987369-ee2550ac-fee3-4e1f-bd7c-acddb89573a9.png)

        iv) Essa execução vai gerar o arquivo .exe
        v) Fim

Executando os testes
      
      Para Executar os testes deve ter instalado (WSL ou o Windows Subsystem para Linux, para execução dos shell scripts).
      i) Abri uma janela de command prompt (cmd)
      ii) Accesar na pasta onde fiz o download dos arquivos e onde foi gerado o arquivo .exe
      iii) Escrever o commando "bash teste_ex_nro.sh" e Executar:
      
            ![image](https://user-images.githubusercontent.com/131888548/234989164-211a1e34-c794-467c-aac7-5e61d088e139.png)
       iv) Exemplo para o Teste 2 Intervalo de Numeros:
         Insiro a quantidade de numeros a carregar:
         
        ![image](https://user-images.githubusercontent.com/131888548/234989874-2f271bc1-66c5-4a0f-916d-4cf9627690ef.png)

        Começo a inserir os numeros:
        
        ![image](https://user-images.githubusercontent.com/131888548/234990101-6b1b2506-b4ea-470d-8e49-7a7f8037f188.png)

        Ao finalizar se mostra a saida na tela:
        
        ![image](https://user-images.githubusercontent.com/131888548/234990310-43e7d0fb-6cd2-4299-a1af-e7fa188961db.png)

Construído com:
      a) Visual Studio e os add-ons de C;
      b) msys64 para compilar com gcc.

Autor:
  Daniel Oscar Abratte
        
          
