#include "pch.h"

#include "AdaptiveElementParserRegistration.h"
#include "AdaptiveTextInput.h"
#include "AdaptiveTextInputRenderer.h"
#include "enums.h"
#include "Util.h"
#include "XamlBuilder.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::Uwp;
using namespace ABI::Windows::Foundation;

namespace AdaptiveCards { namespace Uwp
{
    HRESULT AdaptiveTextInputRenderer::RuntimeClassInitialize() noexcept try
    {
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveTextInputRenderer::Render(
        IAdaptiveCardElement* cardElement,
        IAdaptiveRenderContext* renderContext,
        IAdaptiveRenderArgs* renderArgs,
        ABI::Windows::UI::Xaml::IUIElement** result)
    {
        XamlBuilder::BuildTextInput(cardElement, renderContext, renderArgs, result);
        return S_OK;
    }

    HRESULT AdaptiveTextInputRenderer::FromJson(
        ABI::Windows::Data::Json::IJsonObject* jsonObject,
        ABI::AdaptiveCards::Uwp::IAdaptiveElementParserRegistration* elementParserRegistration,
        ABI::AdaptiveCards::Uwp::IAdaptiveActionParserRegistration* actionParserRegistration,
        ABI::AdaptiveCards::Uwp::IAdaptiveCardElement** element)
    {
        return AdaptiveCards::Uwp::FromJson<AdaptiveCards::Uwp::AdaptiveTextInput, AdaptiveCards::TextInput, AdaptiveCards::TextInputParser>(jsonObject, elementParserRegistration, actionParserRegistration, element);
    }
}}
