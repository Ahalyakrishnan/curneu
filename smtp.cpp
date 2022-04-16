#include<iostream>
#include <CkMailMan.h>
#include <CkEmail.h>
using namespace std;

void ChilkatSample(void)
    {

    CkMailMan mailman;

    mailman.put_SmtpHost("smtp.gmail.com");

    mailman.put_SmtpUsername("mySmtpLogin");
    mailman.put_SmtpPassword("myPassword");

    mailman.put_SmtpSsl(true);
    mailman.put_SmtpPort(465);

    CkEmail email;

    email.put_Subject("This is a test");
    email.put_Body("This is a test");
    email.put_From("ahalya495@gmail.com");
    bool success = email.AddTo("rkanusuya424@gmail.com");

    success = mailman.SendEmail(email);
    if (success != true) {
        std::cout << mailman.lastErrorText() << "\r\n";
        return;
    }

    success = mailman.CloseSmtpConnection();
    if (success != true) {
        std::cout << "Connection to SMTP server not closed cleanly." << "\r\n";
    }

    std::cout << "Mail Sent!" << "\r\n";
    }
