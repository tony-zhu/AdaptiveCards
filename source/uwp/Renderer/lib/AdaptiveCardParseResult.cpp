#include "pch.h"
#include "AdaptiveCardParseResult.h"

#include "AdaptiveCard.h"
#include <windows.foundation.collections.h>
#include <Windows.UI.Xaml.h>
#include "XamlBuilder.h"
#include "XamlHelpers.h"
#include "AdaptiveHostConfig.h"
#include "vector.h"

using namespace concurrency;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::Uwp;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::UI;
using namespace ABI::Windows::UI::Xaml;
using namespace ABI::Windows::UI::Xaml::Controls;

namespace AdaptiveCards { namespace Uwp
{
    AdaptiveCardParseResult::AdaptiveCardParseResult()
    {
    }

    HRESULT AdaptiveCardParseResult::RuntimeClassInitialize()
    {
        return S_OK;
    }

    HRESULT AdaptiveCardParseResult::RuntimeClassInitialize(IAdaptiveCard* value)
    {
        m_adaptiveCard = value;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveCardParseResult::get_AdaptiveCard(IAdaptiveCard** value)
    {
        return m_adaptiveCard.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveCardParseResult::get_Errors(ABI::Windows::Foundation::Collections::IVector<HSTRING>** value)
    {
        return m_errors.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveCardParseResult::get_Warnings(ABI::Windows::Foundation::Collections::IVector<HSTRING>** value)
    {
        return m_warnings.CopyTo(value);
    }
}}
