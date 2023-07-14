#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"
//FString 조작이 가능
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaStringTest, "Beluga.String", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaStringTest::RunTest(const FString& Parameters)
{
	// 생성, 대입
	{
		FString strChar("char");
		FString strChar2(L"wchar");
		FString strChar3(TEXT("wchar"));

		strChar = "char";
		strChar2 = "wchar";
		strChar3 = TEXT("wchar");
	}

	// Printf

	{
		
		TestEqual(TEXT("Printf"), FString::Printf(TEXT("%d %f %s"), 123, 1.0f, TEXT("string")), TEXT("123 1.000000 string"));
	}

	// Format
	{
		{
			FStringFormatNamedArguments NamedArgs;
			NamedArgs.Add(TEXT("First"), 123);
			NamedArgs.Add(TEXT("Second"), 1.0f);
			NamedArgs.Add(TEXT("Third"), TEXT("string"));

			TestEqual(TEXT("FormatNamedArguments"), FString::Format(TEXT("{First} {Second} {Third}"), NamedArgs), TEXT("123 1.000000 string"));
		}
		
		{
			FStringFormatOrderedArguments OrderedArgs;
			OrderedArgs.Add(123);
			OrderedArgs.Add(1.0f);
			OrderedArgs.Add(TEXT("string"));
			
			TestEqual(TEXT("FormatOrderedArgs"), FString::Format(TEXT("{0} {1} {2}"), OrderedArgs), TEXT("123 1.000000 string"));
		}
	}

	FString strApple(TEXT("Apple"));
	FString strBanana(TEXT("Banana"));

	// Operators
	{
		// []
		{
			TestEqual(TEXT("Operator []"), strApple[0], L'A');
		}

		// < >
		{
			TestTrue(TEXT("Operator <"), strApple < strBanana);
		}
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaNameTest, "Beluga.Name", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)
bool FBelugaNameTest::RunTest(const FString& Parameters)
{
	

	static const FName NAME_FunctionalTesting = FName(TEXT("FunctionalTesting"));
	FName Name = NAME_None;

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaTextTest, "Beluga.Text", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)
bool FBelugaTextTest::RunTest(const FString& Parameters)
{
	
	return true;
}