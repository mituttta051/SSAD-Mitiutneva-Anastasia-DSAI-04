#include <iostream>
#include <string>

class Logger {
    static Logger* logger;
    Logger() {}
public:
    static Logger* getInstance() {
        if (logger == nullptr) {
            logger = new Logger();
        }
        return logger;
    }
    void log(const std::string message) {
        std::cout << message << std::endl;
    }
};

Logger* Logger::logger = nullptr;

class DocumentState {
public:
    virtual void handleInput(const std::string& input) = 0;
};

class DraftState : public DocumentState {
    void handleInput(const std::string& input) override {
        std::cout << "Draft state: " << input << std::endl;
    }

};

class ReviewState : public DocumentState {
    void handleInput(const std::string& input) override {
        std::cout << "Review state: " << input << std::endl;
    }

};

class FinalState : public DocumentState{
    void handleInput(const std::string& input) override {
        std::cout << "Final state: " << input << std::endl;
    }

};

class Document {
    DocumentState* currentState;
public:
    Document(DocumentState* initialState) : currentState(initialState) {}
    void changeState(DocumentState* newState) {
        delete currentState;
        currentState = newState;
    }
    void handleInput(const std::string& input) {
        currentState->handleInput(input);
    }
};

class DocumentPrototype {
public:
    virtual DocumentPrototype* clone() const = 0;
};

class ReportType : public DocumentPrototype {
    DocumentPrototype* clone() const override {
        return new ReportType(*this);
    }

};

class InvoiceType : public DocumentPrototype {
    DocumentPrototype* clone() const override {
        return new InvoiceType(*this);
    }

};

int main() {
    Logger* logger = Logger::getInstance();
    logger->log("Application started.");

    Document* document = new Document(new DraftState);
    document->handleInput("Initial input");

    document->changeState(new DraftState);
    document->handleInput("Draft input");

    document->changeState(new ReviewState);
    document->handleInput("Review input");

    document->changeState(new FinalState);
    document->handleInput("Final input");

    DocumentPrototype* report;
    DocumentPrototype* reportClone = report->clone();
    logger->log("Report document logged");

    DocumentPrototype* invoicePrototype;
    DocumentPrototype* invoiceClone = invoicePrototype->clone();
    logger->log("Invoice document cloned.");

    return 0;


}